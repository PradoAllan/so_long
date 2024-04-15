/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:14 by aprado            #+#    #+#             */
/*   Updated: 2024/04/02 18:00:20 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_e(t_map *info)
{
	if (!info->collectables)
	{
		mlx_destroy_window(info->mlxi, info->mlxwin);
		free_all(info);
		exit(1);
	}
	return (1);
}

void	player_left_helper(t_map *info)
{
	if (info->map[info->pline][info->nc] == 'C')
		info->collectables--;
	info->map[info->pline][info->nc] = 'P';
	info->map[info->pline][info->pcolumn] = '0';
	info->pcolumn = info->nc;
	print_moves(info);
}

void	player_right_helper(t_map *info)
{	
	if (info->map[info->pline][info->nc] == 'C')
		info->collectables--;
	info->map[info->pline][info->nc] = 'P';
	info->map[info->pline][info->pcolumn] = '0';
	info->pcolumn = info->nc;
	print_moves(info);
}

void	player_down_helper(t_map *info)
{
	if (info->map[info->nl][info->pcolumn] == 'C')
		info->collectables--;
	info->map[info->nl][info->pcolumn] = 'P';
	info->map[info->pline][info->pcolumn] = '0';
	info->pline = info->nl;
	print_moves(info);
}

void	player_up_helper(t_map *info)
{
	if (info->map[info->nl][info->pcolumn] == 'C')
		info->collectables--;
	info->map[info->nl][info->pcolumn] = 'P';
	info->map[info->pline][info->pcolumn] = '0';
	info->pline = info->nl;
	print_moves(info);
}
