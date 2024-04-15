/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:13:52 by aprado            #+#    #+#             */
/*   Updated: 2024/03/27 11:23:52 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_closed_walls(char **map, int lines)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	len -= 2;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == (lines - 1))
				if (map[i][j] != '1' && map[i][j] != '\n')
					return (-4);
			if (j == 0 || j == len)
				if (map[i][j] != '1' && map[i][j] != '\n')
					return (-4);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_chars(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 'P' && s[i] != 'C' && s[i] != 'E' && s[i] != '1'
			&& s[i] != '0' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_chars_map_right(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!check_chars(map[i]))
			return (-3);
		i++;
	}
	return (1);
}

int	is_map_rectangle(t_map *info)
{
	int	i;
	int	first_line_len;
	int	line_len;

	i = 0;
	if (!info->map)
		return (0);
	first_line_len = ft_strlen(info->map[i]);
	i++;
	if (first_line_len == (info->lines + 1))
		return (-1);
	while (info->map[i])
	{
		line_len = ft_strlen(info->map[i]);
		if (first_line_len != line_len)
			return (-1);
		i++;
	}
	return (1);
}

int	is_there_letters(char **map, t_check letters)
{
	int	i;
	int	j;

	i = -1;
	if (!map)
		return (0);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				letters.p++;
			else if (map[i][j] == 'C')
				letters.c++;
			else if (map[i][j] == 'E')
				letters.e++;
			j++;
		}
	}
	if (!letters.p || !letters.c || !letters.e)
		return (-2);
	if (letters.p > 1 || letters.e > 1)
		return (-2);
	return (1);
}
