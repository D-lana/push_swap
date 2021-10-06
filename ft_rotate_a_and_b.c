/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_and_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:08 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:03:50 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a_and_b(t_point *points)
{
	if (points->count_a > 1)
		points->a = points->a->next;
	if (points->count_b > 1)
		points->b = points->b->next;
	if (points->checker == 0)
		write (1, "rr\n", 3);
}
