/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a_and_b.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:23:39 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:03:31 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a_and_b(t_point *points)
{
	if (points->count_a > 1)
		points->a = points->a->prev;
	if (points->count_b > 1)
		points->b = points->b->prev;
	if (points->checker == 0)
		write (1, "rrr\n", 4);
}
