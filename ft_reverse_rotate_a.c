/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:23:47 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:03:39 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_point *points)
{
	if (points->count_a == 0 || points->count_a == 1)
		return ;
	points->a = points->a->prev;
	if (points->checker == 0)
		write (1, "rra\n", 4);
}
