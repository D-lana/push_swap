/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:01 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:03:45 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_b(t_point *points)
{
	if (points->count_b == 0 || points->count_b == 1)
		return ;
	points->b = points->b->prev;
	if (points->checker == 0)
		write (1, "rrb\n", 4);
}
