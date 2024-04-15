/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_func2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:26:43 by aprado            #+#    #+#             */
/*   Updated: 2024/04/03 11:47:45 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_validation(t_map *info)
{
	t_check	validation;

	validation.p = 0;
	validation.e = 0;
	validation.c = 0;
	if (!info->map)
		return (0);
	if (is_map_rectangle(info) == -1)
		return (NOT_RECTANGLE);
	if (is_there_letters(info->map, validation) == -2)
		return (NOT_RIGHT_LETTERS);
	if (is_chars_map_right(info->map) == -3)
		return (NOT_RIGHT_CHARS);
	if (is_map_closed_walls(info->map, info->lines) == -4)
		return (NOT_WALLED);
	if (!info->map_copy)
		return (-5);
	if (is_valid_path(info) == -5)
		return (NOT_PLAYABLE);
	return (1);
}

int	is_valid_path(t_map *info)
{
	int	i;
	int	j;

	i = 0;
	is_map_playable(info, info->pline, info->pcolumn);
	while (info->map_copy[i])
	{
		j = 0;
		while (info->map_copy[i][j])
		{
			if (info->map_copy[i][j] == 'C'
				|| info->map_copy[i][j] == 'E')
				return (-5);
			j++;
		}
		i++;
	}
	return (1);
}

void	is_map_playable(t_map *info, int x, int y)
{
	if (info->map_copy[x][y] == 'E')
		info->map_copy[x][y] = '1';
	if (x < 1 || x > info->lines || y < 1 || y > info->column
		|| info->map_copy[x][y] == '1')
		return ;
	info->map_copy[x][y] = '1';
	is_map_playable(info, x - 1, y);
	is_map_playable(info, x + 1, y);
	is_map_playable(info, x, y - 1);
	is_map_playable(info, x, y + 1);
}

int	revstrncmp(char *compare, char *map_name, int n)
{
	int	i;
	int	ii;

	if (n == 0)
		return (0);
	i = 0;
	ii = 0;
	while (map_name[i])
		i++;
	while (compare[ii])
		ii++;
	while (n--)
		if (map_name[i--] != compare[ii--])
			return (0);
	return (1);
}
