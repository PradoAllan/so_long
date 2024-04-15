/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:10:13 by aprado            #+#    #+#             */
/*   Updated: 2024/04/02 18:44:52 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

int	free_x(t_map *info)
{
	if (!info)
		return (0);
	mlx_destroy_window(info->mlxi, info->mlxwin);
	free_all(info);
	exit(1);
	return (1);
}

int	so_long_gameplay(t_map *info)
{
	info->mlxi = mlx_init();
	if (!info->mlxi)
		return (0);
	info->mlximg = populate_img(info);
	info->mlxwin = mlx_new_window(info->mlxi, 64 * (info->column - 1),
			64 * info->lines, "so_long");
	if (!info->mlxwin)
		return (0);
	mlx_key_hook(info->mlxwin, moves, info);
	mlx_hook(info->mlxwin, 17, 0, free_x, info);
	populate_window(info);
	mlx_loop(info->mlxi);
	return (1);
}

int	so_long(char **map, int lines)
{
	int		error;
	t_map	*info;

	info = populate_struct_info(map, lines);
	error = map_validation(info);
	if (error != 1)
	{
		free_matrix(info->map_copy, info->lines);
		free(info);
		return (error);
	}
	if (so_long_gameplay(info) == 0)
	{
		free_matrix(info->map_copy, info->lines);
		free(info);
		return (0);
	}
	free_matrix(info->map_copy, info->lines);
	free(info);
	return (1);
}

int	main(int ac, char **av)
{
	int		lines;
	int		error;
	char	*map_name;
	char	**map;

	if (ac != 2)
		return (ft_puterror(NO_PARAMETERS), NO_PARAMETERS);
	map_name = av[1];
	if (!revstrncmp(".ber", map_name, 5))
		return (ft_puterror(NOT_BER), NOT_BER);
	lines = count_lines(map_name);
	if (lines == 0)
		return (ft_puterror(0), 0);
	map = get_map(map_name, lines);
	if (!map)
		return (ft_puterror(-10), 0);
	error = so_long(map, lines);
	if (error != 1)
		return (free_matrix(map, lines), ft_puterror(error), 0);
	free_matrix(map, lines);
	return (0);
}
