/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:49 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:04:33 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_point *points)

{
	t_list	*cut_list;
	t_list	*p_next;

	if (points->count_b > 1)
	{
		ft_cut_list(&cut_list, &points->b);
		p_next = points->b->next;
		ft_paste_list(&cut_list, &p_next);
		if (points->checker == 0)
			write (1, "sb\n", 3);
	}
}
