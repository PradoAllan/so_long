/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:29:55 by aprado            #+#    #+#             */
/*   Updated: 2024/04/03 11:32:41 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *map_name)
{
	int		i;
	int		fd;
	char	*s;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (FD_ERROR);
	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	ft_puterror(int error)
{
	if (error == NO_PARAMETERS)
		return (ft_putstr_fd("Error\n./so_long maps/mapname.ber", 2));
	else if (error == NOT_RECTANGLE)
		return (ft_putstr_fd("Error\nMAP IS NOT RECTANGLE", 2));
	else if (error == NOT_RIGHT_LETTERS)
		return (ft_putstr_fd("Error\nSPECIAL LETTERS AREN`T RIGHT", 2));
	else if (error == NOT_RIGHT_CHARS)
		return (ft_putstr_fd("Error\nONLY 1, 0, P, C and E", 2));
	else if (error == NOT_WALLED)
		return (ft_putstr_fd("Error\nWALLS ARE NOT RIGHT", 2));
	else if (error == NOT_PLAYABLE)
		return (ft_putstr_fd("Error\nMAP IS NOT PLAYABLE", 2));
	else if (error == NOT_BER)
		return (ft_putstr_fd("Error\nMAP EXTENSION IS NOT .BER", 2));
	else if (error == FD_ERROR)
		return (ft_putstr_fd("Error\nFILE DESCRIPTOR ERROR", 2));
	else
		return (ft_putstr_fd("Error\nAN ERROR OCCURED", 2));
}

char	**get_map(char *map_name, int lines)
{
	int		fd;
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	map[lines] = NULL;
	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}

char	**copy_map(char **map, int lines)
{
	int		i;
	int		j;
	int		len;
	char	**copy;

	if (!map)
		return (NULL);
	copy = malloc(sizeof(char *) * (lines + 1));
	copy[lines] = NULL;
	i = -1;
	while (++i < lines)
	{
		j = 0;
		len = ft_strlen(map[i]);
		copy[i] = malloc(sizeof(char) * (len + 1));
		if (!copy[i])
			return (free_matrix(copy, i), NULL);
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][len] = '\0';
	}
	return (copy);
}

void	free_matrix(char **map, int lines)
{
	if (!map)
		return ;
	while (lines--)
		free(map[lines]);
	free(map);
}
