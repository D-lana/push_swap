/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:20:26 by dlana             #+#    #+#             */
/*   Updated: 2021/09/30 18:34:33 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_record_id(t_point *points, int *array)
{
	int		count;
	int		i;
	t_list	*tmp;

	tmp = points->a;
	i = 0;
	count = 0;
	while (i != points->count_a)
	{
		while (tmp->numb != array[count] && count <= points->count_a)
			count++;
		if (tmp->numb == array[count])
		{
			tmp->id_new = count;
			tmp = tmp->next;
		}
		i++;
		count = 0;
	}
}

static void	ft_check_duplicate(t_point *points, int *array)
{
	int	count;

	count = 0;
	while (count < points->count_a)
	{
		if (count > 0 && array[count] == array[count - 1])
			ft_error();
		if (count < points->count_a - 1 && array[count] == array[count + 1])
			ft_error();
		count++;
	}
}

static int	*ft_go_to_array(int *array, int *start, int *end, int middle)
{
	int	left;
	int	right;
	int	tmp;

	left = *start;
	right = *end;
	while (left < right)
	{
		while (array[left] < middle && left < right)
			left++;
		while (array[right] > middle && left < right)
			right--;
		if (array[left] == array[right] && left != right)
			ft_error();
		if (array[left] > array[right])
		{
			tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
		}
	}
	*start = left;
	*end = right;
	return (array);
}

static int	*ft_quick_sort(int *array, int start, int end, int count)
{
	int	middle;
	int	middle_id;
	int	left;
	int	right;

	if (start < end && start != end)
	{
		left = start;
		right = end;
		middle_id = (left + right) / 2;
		middle = array[middle_id];
		*array = *ft_go_to_array(array, &left, &right, middle);
		if (right == end && left > start)
			left--;
		if (start <= left && left != end)
			ft_quick_sort(array, start, left, count);
		if (right == start && right < end)
			right++;
		if (right <= end && start != right)
			ft_quick_sort(array, right, end, count);
	}
	return (array);
}

void	ft_sort_array(t_point *points)
{
	int		*array;
	int		count;
	t_list	*tmp;

	tmp = points->a;
	count = 0;
	array = malloc(sizeof(int) * points->count_a);
	while (count != points->count_a)
	{
		array[count] = tmp->numb;
		tmp = tmp->next;
		count++;
	}
	*array = *ft_quick_sort(array, 0, (count - 1), (count - 1));
	ft_check_duplicate(points, array);
	ft_record_id(points, array);
	free(array);
}
