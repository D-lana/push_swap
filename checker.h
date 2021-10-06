/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:19:21 by dlana             #+#    #+#             */
/*   Updated: 2021/10/01 21:16:13 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"

int		ft_read_and_make_instructions(t_point *points);
int		ft_make_instructions(t_point *points, char *line);
void	ft_sort_array_to_check(t_point *points);
void	ft_check_instructions(const char *s, int i);

#endif