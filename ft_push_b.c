/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:23:31 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:03:19 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_point *points)
{
	t_list	*tmp;

	if (points->count_a == 0)
		return ;
	ft_cut_list(&tmp, &points->a);
	if (points->b == 0)
	{
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	if (points->b != 0)
		ft_paste_list(&tmp, &points->b);
	points->b = tmp;
	points->count_a--;
	points->count_b++;
	if (points->count_a == 0)
		points->a = points->empty_list;
	if (points->checker == 0)
		write (1, "pb\n", 3);
}
