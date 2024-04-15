/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:36:48 by aprado            #+#    #+#             */
/*   Updated: 2024/04/08 19:09:51 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_map *info)
{
	if (!info)
		return ;
	mlx_destroy_image(info->mlxi, info->mlximg->floor);
	mlx_destroy_image(info->mlxi, info->mlximg->wall);
	mlx_destroy_image(info->mlxi, info->mlximg->pr);
	mlx_destroy_image(info->mlxi, info->mlximg->c);
	mlx_destroy_image(info->mlxi, info->mlximg->e);
	mlx_destroy_image(info->mlxi, info->mlximg->pl);
	mlx_destroy_image(info->mlxi, info->mlximg->pu);
	mlx_destroy_image(info->mlxi, info->mlximg->pd);
	mlx_destroy_image(info->mlxi, info->mlximg->pe);
	free(info->mlximg);
	free_matrix(info->map_copy, info->lines);
	free_matrix(info->map, info->lines);
	//mlx_destroy_display(info->mlxi);
	//NO MAC, PRECISA COMENTAR ESSA FUNC...
	free(info->mlxi);
	free(info);
}

int	get_c_number(t_map *info)
{
	int	i;
	int	j;
	int	collectable;

	i = 0;
	collectable = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'C')
				collectable++;
			j++;
		}
		i++;
	}
	return (collectable);
}

t_map	*populate_struct_info(char **map, int lines)
{
	t_map	*info;

	info = malloc(sizeof(t_map));
	if (!info)
		return (0);
	info->map = map;
	info->lines = lines;
	info->map_copy = copy_map(map, lines);
	info->pline = get_p_line(map, lines, info);
	info->pcolumn = get_p_column(map, lines, info);
	info->column = ft_strlen(map[0]);
	info->collectables = get_c_number(info);
	info->moves = 0;
	return (info);
}

int	get_p_line(char **map, int lines, t_map *info)
{
	int	i;
	int	j;

	i = 0;
	(void)info;
	while (i < (lines - 1))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_p_column(char **map, int lines, t_map *info)
{
	int	line;
	int	i;

	i = 0;
	(void)info;
	line = get_p_line(map, lines, info);
	while (map[line][i])
	{
		if (map[line][i] == 'P')
			return (i);
		i++;
	}
	return (0);
}
