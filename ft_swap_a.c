/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:43 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:04:26 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_point *points)
{
	t_list	*cut_list;
	t_list	*p_next;

	if (points->count_a > 1)
	{
		ft_cut_list(&cut_list, &points->a);
		p_next = points->a->next;
		ft_paste_list(&cut_list, &p_next);
		if (points->checker == 0)
			write (1, "sa\n", 3);
	}
}
