/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:30:38 by dlana             #+#    #+#             */
/*   Updated: 2021/10/01 18:32:15 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_make_swap(t_point *points, char *line, int i)
{
	if (line[i + 1] == 'a' && line[i + 2] == '\n')
		ft_swap_a(points);
	else if (line[i + 1] == 'b' && line[i + 2] == '\n')
		ft_swap_b(points);
	else if (line[i + 1] == 's' && line[i + 2] == '\n')
		ft_swap_a_and_b(points);
	else
		ft_error();
}

static void	ft_make_push(t_point *points, char *line, int i)
{
	if (line[i + 1] == 'a' && line[i + 2] == '\n')
		ft_push_a(points);
	else if (line[i + 1] == 'b' && line[i + 2] == '\n')
		ft_push_b(points);
	else
		ft_error();
}

static void	ft_make_rotate(t_point *points, char *line, int i)
{
	if (line[i + 1] == 'a' && line[i + 2] == '\n')
		ft_rotate_a(points);
	else if (line[i + 1] == 'b' && line[i + 2] == '\n')
		ft_rotate_b(points);
	else if (line[i + 1] == 'r' && line[i + 2] == '\n')
		ft_rotate_a_and_b(points);
	else
		ft_error();
}

static void	ft_make_reverse_rotate(t_point *points, char *line, int i)
{
	if (line[i + 1] == 'a' && line[i + 2] == '\n')
		ft_reverse_rotate_a(points);
	else if (line[i + 1] == 'b' && line[i + 2] == '\n')
		ft_reverse_rotate_b(points);
	else if (line[i + 1] == 'r' && line[i + 2] == '\n')
		ft_reverse_rotate_a_and_b(points);
	else
		ft_error();
}

int	ft_make_instructions(t_point *points, char *line)
{
	int	i;
	int	count_instructions;

	i = 0;
	count_instructions = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 's')
			ft_make_swap(points, line, i);
		else if (line[i] == 'p')
			ft_make_push(points, line, i);
		else if (line[i] == 'r' && line[i + 2] == '\n')
			ft_make_rotate(points, line, i);
		else if (line[i] == 'r' && line[i + 1] == 'r')
		{
			i++;
			ft_make_reverse_rotate(points, line, i);
		}
		else
			ft_error();
		count_instructions++;
		i = i + 3;
	}
	return (count_instructions);
}
