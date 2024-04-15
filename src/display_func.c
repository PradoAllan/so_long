/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:15:41 by aprado            #+#    #+#             */
/*   Updated: 2024/04/02 18:12:13 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_map *info)
{
	info->moves++;
	ft_putstr_fd("Car moves: ", 1);
	ft_putnbr_fd(info->moves, 1);
	ft_putchar_fd('\r', 1);
}

t_img	*img_helper(t_map *info, t_img *img)
{
	int	x;
	int	y;

	img->floor = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/0.xpm", &x, &y);
	img->wall = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/1.xpm", &x, &y);
	img->c = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/C.xpm", &x, &y);
	img->pr = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/Pright.xpm", &x, &y);
	img->e = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/E.xpm", &x, &y);
	img->pl = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/Pleft.xpm", &x, &y);
	img->pu = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/Pup.xpm", &x, &y);
	img->pd = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/Pdown.xpm", &x, &y);
	img->pe = mlx_xpm_file_to_image(info->mlxi,
			"./assets/xpm/PatE.xpm", &x, &y);
	return (img);
}

t_img	*populate_img(t_map *info)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	return (img_helper(info, img));
}

void	populate_window_helper(t_map *info, int j, int i, char c)
{
	if (c == '1')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->wall, j * 64, i * 64);
	else if (c == '0')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->floor, j * 64, i * 64);
	else if (c == 'P')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->pr, j * 64, i * 64);
	else if (c == 'C')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->c, j * 64, i * 64);
	else if (c == 'E')
		mlx_put_image_to_window(info->mlxi, info->mlxwin,
			info->mlximg->e, j * 64, i * 64);
}

int	populate_window(t_map *info)
{
	int	i;
	int	j;

	i = -1;
	while (info->map[++i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '1')
				populate_window_helper(info, j, i, '1');
			else if (info->map[i][j] == '0')
				populate_window_helper(info, j, i, '0');
			else if (info->map[i][j] == 'P')
				populate_window_helper(info, j, i, 'P');
			else if (info->map[i][j] == 'C')
				populate_window_helper(info, j, i, 'C');
			else if (info->map[i][j] == 'E')
				populate_window_helper(info, j, i, 'E');
			j++;
		}
	}
	return (1);
}
