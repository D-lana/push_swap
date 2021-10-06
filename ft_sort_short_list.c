/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_short_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:19:39 by dlana             #+#    #+#             */
/*   Updated: 2021/09/29 20:41:17 by dlana            ###   ########.fr       */
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

static void	sort_5_numb(t_point *points)
{
	int	count;

	count = points->count_a;
	while (count != 0)
	{
		if (points->a->id_new == 0 || points->a->id_new == 1)
			ft_push_b(points);
		else
			ft_rotate_a(points);
		count--;
	}
	sort_3_numb(points);
	if (points->b->numb < points->b->next->numb)
		ft_swap_b(points);
	ft_push_a(points);
	ft_push_a(points);
	return ;
}

static void	sort_4_numb(t_point *points)
{
	if (points->a->id_new == 2)
		ft_swap_a(points);
	ft_push_b(points);
	sort_3_numb(points);
	ft_push_a(points);
	if (points->a->id_new == 1)
		ft_swap_a(points);
	if (points->a->id_new == 3)
		ft_rotate_a(points);
	return ;
}

static void	sort_2_numb(t_point *points)
{
	if (points->a->numb > points->a->next->numb)
		ft_reverse_rotate_a(points);
	return ;
}

void	ft_sort_short_list(t_point *points)
{
	if (points->count_a == 2)
		sort_2_numb(points);
	if (points->count_a == 3)
		sort_3_numb(points);
	if (points->count_a == 4)
		sort_4_numb(points);
	if (points->count_a == 5)
		sort_5_numb(points);
}
