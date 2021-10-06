/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_long_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:31 by dlana             #+#    #+#             */
/*   Updated: 2021/10/02 20:30:39 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_numb(t_point *p)
{
	if (p->a->numb > p->a->prev->numb && p->a->numb > p->a->next->numb)
		ft_rotate_a(p);
	if (p->a->next->numb > p->a->numb && p->a->next->numb > p->a->prev->numb)
		ft_reverse_rotate_a(p);
	if (p->a->numb > p->a->next->numb)
		ft_swap_a(p);
	return ;
}

static int	ft_check_short_way(t_list *list, int count, int i)
{
	t_list	*tmp;
	int		top;
	int		back;

	top = 0;
	back = 0;
	tmp = list;
	while ((tmp->id_new != i - 1) && top < count)
	{
		tmp = tmp->next;
		top++;
	}
	tmp = list;
	while ((tmp->prev->id_new != i - 1) && back < count)
	{
		tmp = tmp->prev;
		back++;
	}
	if (top <= back)
		return (0);
	else
		return (1);
}

static int	ft_init_i(t_point *points)
{
	int	i;

	i = 2;
	if (points->count_a > 5 && points->count_a <= 50)
		i = 5;
	if (points->count_a > 50 && points->count_a <= 150)
		i = 10;
	if (points->count_a > 150 && points->count_a <= 500)
		i = 35;
	if (points->count_a > 500)
		i = 35;
	return (i);
}

static void	ft_push_and_sort_to_b(t_point *points, int min_id)
{
	int	i;
	int	count;
	int	id_max;

	i = 0;
	count = points->count_a;
	id_max = points->count_a - 3;
	while (points->count_a > 3)
	{
		while (count > 0 && points->count_a > 3)
		{
			if (points->a->id_new <= min_id + i && points->a->id_new < id_max)
			{
				ft_push_b(points);
				if (points->b->id_new < i && points->count_a > 2)
					ft_rotate_b(points);
				i++;
			}
			else
				ft_rotate_a(points);
			count--;
		}
		count = points->count_a;
	}
}

void	ft_sort_long_list(t_point *points)
{
	int	min_id;
	int	way;

	min_id = ft_init_i(points);
	ft_push_and_sort_to_b(points, min_id);
	sort_3_numb(points);
	while (points->count_b != 0)
	{
		way = ft_check_short_way(points->b, points->count_b, points->a->id_new);
		if (way == 0)
		{
			while (points->b->id_new != points->a->id_new - 1)
				ft_rotate_b(points);
			ft_push_a(points);
		}
		else
		{
			while (points->b->prev->id_new != points->a->id_new - 1)
				ft_reverse_rotate_b(points);
			ft_reverse_rotate_b(points);
			ft_push_a(points);
		}
	}
}
