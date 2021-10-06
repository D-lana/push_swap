/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:19:52 by dlana             #+#    #+#             */
/*   Updated: 2021/10/01 18:07:05 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_numb_count_and_first_start(char *s, int *numb_count)
{
	int	i;
	int	numb_count_tmp;

	i = 0;
	numb_count_tmp = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			while (s[i] != ' ' && s[i] != '\0')
				i++;
			numb_count_tmp++;
		}
		if (s[i] != '\0')
			i++;
	}
	*numb_count = numb_count_tmp;
	return (i);
}

static void	ft_search_start(char *argc, int *start)
{
	int	i;

	i = *start;
	if (argc[i] == '\0' && i > 0)
		i--;
	while (argc[i] == ' ' && i > 0)
		i--;
	while (argc[i] != ' ' && i > 0)
		i--;
	*start = i;
}

static void	tf_check_min_max(long int rezult, int c)
{
	if (rezult * c < INT_MIN)
		ft_error();
	if (rezult * c > INT_MAX)
		ft_error();
}

static int	ft_atoi_for_str_with_space(const char *str, int start)
{
	int			i;
	int			c;
	long int	rezult;

	i = start;
	c = 1;
	rezult = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
	{
		if (str[i] == '-')
			c = (c * -1);
		i++;
	}
	while (str[i] != ' ' && str[i] != '\0')
	{
		if ((str[i] < 48 || str[i] > 57))
			ft_error();
		rezult = rezult * 10 + (str[i] - '0');
		i++;
	}
	tf_check_min_max(rezult, c);
	return (rezult * c);
}

void	ft_parser(t_point *points, char **argc, int count)
{
	int	numb;
	int	numb_count;
	int	start_str;

	numb_count = 0;
	while ((--count) > 0)
	{
		start_str = ft_numb_count_and_first_start(argc[count], &numb_count);
		if (numb_count > 1)
		{
			while (start_str > 0)
			{
				ft_search_start(argc[count], &start_str);
				numb = ft_atoi_for_str_with_space(argc[count], start_str);
				ft_create_a(points, numb, count - 1);
				points->count_a += 1;
			}
		}
		else if (numb_count == 1)
		{
			numb = ft_atoi_for_str_with_space(argc[count], 0);
			ft_create_a(points, numb, count - 1);
			points->count_a += 1;
		}
	}
}
