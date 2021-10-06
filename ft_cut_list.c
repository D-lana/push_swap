/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:20:56 by dlana             #+#    #+#             */
/*   Updated: 2021/09/29 20:20:56 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cut_list(t_list **cut_list, t_list **p_to_struct)
{
	t_list	*p_2;
	t_list	*p_tail;

	(*cut_list) = (*p_to_struct);
	p_2 = (*p_to_struct)->next;
	p_tail = (*p_to_struct);
	p_tail = p_tail->prev;
	(*p_to_struct) = (*p_to_struct)->next;
	(*p_to_struct)->prev = p_tail;
	p_tail->next = (*p_to_struct);
}
