/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:22:28 by dlana             #+#    #+#             */
/*   Updated: 2021/09/29 20:31:19 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_paste_list(t_list **paste_list, t_list **stack)
{
	t_list	*p_prev;
	t_list	*stack_tmp;
	t_list	*paste_list_tmp;

	paste_list_tmp = *paste_list;
	stack_tmp = *stack;
	p_prev = stack_tmp->prev;
	paste_list_tmp->next = stack_tmp;
	paste_list_tmp->prev = p_prev;
	p_prev->next = paste_list_tmp;
	stack_tmp->prev = paste_list_tmp;
}
