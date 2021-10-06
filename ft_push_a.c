/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:22:51 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:03:08 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_point *points)
{
	t_list	*tmp;

	if (points->count_b == 0)
		return ;
	ft_cut_list(&tmp, &points->b);
	if (points->a == 0)
	{
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	if (points->a != 0)
		ft_paste_list(&tmp, &points->a);
	points->a = tmp;
	points->count_b--;
	points->count_a++;
	if (points->count_b == 0)
		points->b = points->empty_list;
	if (points->checker == 0)
		write (1, "pa\n", 3);
}
