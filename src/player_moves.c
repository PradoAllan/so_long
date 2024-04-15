/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:01:49 by aprado            #+#    #+#             */
/*   Updated: 2024/04/02 18:03:22 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int keycode, t_map *info)
{
	if (keycode == UP_ARROW)
		player_up(info, 1);
	else if (keycode == RIGHT_ARROW)
		player_right(info, 1);
	else if (keycode == LEFT_ARROW)
		player_left(info, 1);
	else if (keycode == DOWN_ARROW)
		player_down(info, 1);
	else if (keycode == ESC)
	{
		mlx_destroy_window(info->mlxi, info->mlxwin);
		free_all(info);
		exit(0);
	}
	return (1);
}

int	player_left(t_map *info, int column)
{
	info->nc = info->pcolumn - column;
	if (info->nc != 0)
	{
		info->newc = info->map[info->pline][info->nc];
		info->oldc = info->map[info->pline][info->pcolumn];
		if (info->map[info->pline][info->nc] == 'E')
		{
			if (!info->collectables)
				is_e(info);
		}
		else if (info->map[info->pline][info->nc] == '0')
			player_left_helper(info);
		else if (info->map[info->pline][info->nc] == 'C')
			player_left_helper(info);
		else
			return (0);
		new_left_assets(info);
		return (1);
	}
	return (0);
}

int	player_right(t_map *info, int column)
{
	info->nc = info->pcolumn + column;
	if (info->nc < (info->column - 1))
	{
		info->newc = info->map[info->pline][info->nc];
		info->oldc = info->map[info->pline][info->pcolumn];
		if (info->map[info->pline][info->nc] == 'E')
		{
			if (!info->collectables)
				is_e(info);
		}
		else if (info->map[info->pline][info->nc] == '0')
			player_right_helper(info);
		else if (info->map[info->pline][info->nc] == 'C')
			player_right_helper(info);
		else
			return (0);
		new_right_assets(info);
		return (1);
	}
	return (0);
}

int	player_down(t_map *info, int line)
{
	info->nl = info->pline + line;
	if (info->nl < info->lines)
	{
		info->newc = info->map[info->nl][info->pcolumn];
		info->oldc = info->map[info->pline][info->pcolumn];
		if (info->map[info->nl][info->pcolumn] == 'E')
		{
			if (!info->collectables)
				is_e(info);
		}
		else if (info->map[info->nl][info->pcolumn] == '0')
			player_down_helper(info);
		else if (info->map[info->nl][info->pcolumn] == 'C')
			player_down_helper(info);
		else
			return (0);
		new_down_assets(info);
		return (1);
	}
	return (0);
}

int	player_up(t_map *info, int line)
{
	info->nl = info->pline - line;
	if (info->nl != 0)
	{
		info->newc = info->map[info->nl][info->pcolumn];
		info->oldc = info->map[info->pline][info->pcolumn];
		if (info->map[info->nl][info->pcolumn] == 'E')
		{
			if (!info->collectables)
				is_e(info);
		}
		else if (info->map[info->nl][info->pcolumn] == '0')
			player_up_helper(info);
		else if (info->map[info->nl][info->pcolumn] == 'C')
			player_up_helper(info);
		else
			return (0);
		new_up_assets(info);
		return (1);
	}
	return (0);
}
