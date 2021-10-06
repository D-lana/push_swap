/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_make_instructions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:39:52 by dlana             #+#    #+#             */
/*   Updated: 2021/10/02 14:21:58 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_killer(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}

static char	*ft_join_str_and_ch(const char *s1, char c, int rd)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = 0;
	if (c == '\n')
		ft_check_instructions(s1, rd - 1);
	if (!c)
		ft_error();
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!s2)
		ft_error();
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = c;
	i++;
	s2[i] = '\0';
	return (s2);
}

static int	ft_read_instructions(char **line)
{
	int		rd;
	char	ch;
	char	*str;

	rd = 0;
	*line = malloc(sizeof(char));
	while (read(0, &ch, 1) > 0)
	{
		str = *line;
		*line = ft_join_str_and_ch(str, ch, rd);
		ft_killer(&str);
		rd++;
	}
	return (rd);
}

int	ft_read_and_make_instructions(t_point *points)
{
	int		rd;
	char	*line;
	int		count_instructions;

	line = NULL;
	count_instructions = 0;
	rd = ft_read_instructions(&line);
	if (line[0] != '\0')
		count_instructions = ft_make_instructions(points, line);
	free (line);
	line = NULL;
	return (count_instructions);
}
