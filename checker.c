/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:32:36 by dlana             #+#    #+#             */
/*   Updated: 2021/10/01 19:13:25 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_create_empty_list(t_point *points)
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
	int		count_instructions;

	points.count_a = 0;
	points.count_b = 0;
	points.checker = 1;
	i = argv - 1;
	ft_parser(&points, argc, i + 1);
	if (points.count_a < 1)
		exit(EXIT_SUCCESS);
	ft_create_empty_list(&points);
	count_instructions = ft_read_and_make_instructions(&points);
	ft_sort_array_to_check(&points);
	exit(EXIT_SUCCESS);
}
