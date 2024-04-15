/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:09:05 by aprado            #+#    #+#             */
/*   Updated: 2024/04/02 17:32:19 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_left_assets(t_map *info)
{
	int	x;
	int	y;

	x = info->pline;
	y = info->pcolumn;
	if (!info)
		return ;
	mlx_put_image_to_window(info->mlxi, info->mlxwin, info->mlximg->pl,
		y * 64, x * 64);
	y++;
	if (info->oldc == 'E')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->e, y * 64, x * 64);
	else if (info->map[x][y] != '1')
	{
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->floor, y * 64, x * 64);
	}
}

void	new_right_assets(t_map *info)
{
	int	x;
	int	y;

	x = info->pline;
	y = info->pcolumn;
	if (!info)
		return ;
	mlx_put_image_to_window(info->mlxi, info->mlxwin,
		info->mlximg->pr, y * 64, x * 64);
	y--;
	if (info->oldc == 'E')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->e, y * 64, x * 64);
	else if (info->map[x][y] != '1')
	{
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->floor, y * 64, x * 64);
	}
}

void	new_up_assets(t_map *info)
{
	int	x;
	int	y;

	x = info->pline;
	y = info->pcolumn;
	if (!info)
		return ;
	mlx_put_image_to_window(info->mlxi, info->mlxwin,
		info->mlximg->pu, y * 64, x * 64);
	x++;
	if (info->oldc == 'E')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->e, y * 64, x * 64);
	else if (info->map[x][y] != '1')
	{
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->floor, y * 64, x * 64);
	}
}

void	new_down_assets(t_map *info)
{
	int	x;
	int	y;

	x = info->pline;
	y = info->pcolumn;
	if (!info)
		return ;
	mlx_put_image_to_window(info->mlxi, info->mlxwin,
		info->mlximg->pd, y * 64, x * 64);
	x--;
	if (info->oldc == 'E')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->e, y * 64, x * 64);
	else if (info->map[x][y] != '1')
	{
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->floor, y * 64, x * 64);
	}
}
