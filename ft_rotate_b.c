/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:22 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:04:00 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_b(t_point *points)
{
	if (points->count_b > 1)
		points->b = points->b->next;
	if (points->checker == 0)
		write (1, "rb\n", 3);
}
