/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:20:07 by dlana             #+#    #+#             */
/*   Updated: 2021/10/02 13:48:47 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				id_new;
	int				numb;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_point
{
	int		need_sort;
	int		checker;
	int		count_a;
	int		count_b;
	t_list	*a;
	t_list	*b;
	t_list	*empty_list;
}				t_point;

void	ft_parser(t_point *points, char **argc, int count);
void	ft_error(void);
void	ft_create_a(t_point *points, int numb, int i);

void	ft_swap_a(t_point *points);
void	ft_swap_b(t_point *points);
void	ft_swap_a_and_b(t_point *points);
void	ft_push_a(t_point *points);
void	ft_push_b(t_point *points);
void	ft_rotate_a(t_point *points);
void	ft_rotate_b(t_point *points);
void	ft_rotate_a_and_b(t_point *points);
void	ft_reverse_rotate_a(t_point *points);
void	ft_reverse_rotate_b(t_point *points);
void	ft_reverse_rotate_a_and_b(t_point *points);

void	ft_cut_list(t_list **cut_list, t_list **p_to_struct);
void	ft_paste_list(t_list **paste_list, t_list **stack);

void	ft_sort_array(t_point *points);
void	ft_sort_long_list(t_point *points);
void	ft_sort_short_list(t_point *points);

#endif