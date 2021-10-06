/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:20:47 by dlana             #+#    #+#             */
/*   Updated: 2021/10/02 14:58:54 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_already_sorted_list(t_point *points)
{
	if (points->a->numb > points->a->next->numb)
	{
		points->need_sort = 1;
	}
}

void	ft_create_a(t_point *points, int numb, int i)
{
	int		number;
	t_list	*tmp;

	number = numb;
	tmp = malloc(sizeof(t_list));
	if (!tmp)
		ft_error();
	tmp->numb = number;
	tmp->id_new = i;
	if (points->a == 0)
	{
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	if (points->a != 0)
	{
		tmp->prev = points->a->prev;
		points->a->prev->next = tmp;
		tmp->next = points->a;
		points->a->prev = tmp;
	}
	points->a = tmp;
	ft_check_already_sorted_list(points);
}
