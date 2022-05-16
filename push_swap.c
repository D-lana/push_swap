/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:19:08 by dlana             #+#    #+#             */
/*   Updated: 2021/10/02 14:12:48 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_empty_list(t_point *points)
{
	points->empty_list = malloc(sizeof(t_list));
	if (!points->empty_list)
		ft_error();
	points->empty_list->next = points->empty_list;
	points->empty_list->prev = points->empty_list;
}

int	main(int argv, char **argc)
{
	t_point	points;
	int		i;

	points.count_a = 0;
	points.count_b = 0;
	points.checker = 0;
	points.need_sort = 0;
	i = argv - 1;
	ft_parser(&points, argc, i + 1);
	ft_create_empty_list(&points);
	ft_sort_array(&points);
	if (points.count_a >= 2 && points.count_a <= 5 && points.need_sort == 1)
		ft_sort_short_list(&points);
	if (points.count_a >= 6 && points.need_sort == 1)
		ft_sort_long_list(&points);
	exit(EXIT_SUCCESS);
}
