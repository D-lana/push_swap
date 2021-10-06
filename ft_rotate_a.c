/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:15 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 21:03:55 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_point *points)
{
	if (points->count_a > 1)
		points->a = points->a->next;
	if (points->checker == 0)
		write (1, "ra\n", 3);
}
