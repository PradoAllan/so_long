/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:06:22 by aprado            #+#    #+#             */
/*   Updated: 2024/04/08 19:08:11 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libftsrc/libft.h"

# ifdef __linux__
# include "./minilibx-linux/mlx.h"
# define UP_ARROW 65362
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define ESC 65307
# else
#  include "./minilibx-mac/mlx.h"
#  define UP_ARROW        13 //W
#  define DOWN_ARROW        1 //S
#  define LEFT_ARROW        0 //A
#  define RIGHT_ARROW        2 //D
#  define ESC        53 //ESC
# endif



enum e_errors
{
	NO_PARAMETERS = 0,
	NOT_RECTANGLE= -1,
	NOT_RIGHT_LETTERS= -2,
	NOT_RIGHT_CHARS= -3,
	NOT_WALLED= -4,
	NOT_PLAYABLE= -5,
	NOT_BER= -6,
	FD_ERROR = -7
};

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*pr;
	void	*pl;
	void	*pu;
	void	*pd;
	void	*pe;
	void	*c;
	void	*e;
}		t_img;

typedef struct s_map
{
	int		collectables;
	int		lines;
	int		nl;
	int		column;
	int		nc;
	int		moves;
	int		pline;
	int		pcolumn;
	char	oldc;
	char	newc;
	char	**map;
	char	**map_copy;
	void	*mlxi;
	void	*mlxwin;
	t_img	*mlximg;
}		t_map;

typedef struct s_check
{
	int	p;
	int	c;
	int	e;
}		t_check;

/*-- MAP VALIDATIONS --*/
int		map_validation(t_map *info);
int		is_map_rectangle(t_map *info);
int		is_there_letters(char **map, t_check letters);
int		is_chars_map_right(char **map);
int		is_map_closed_walls(char **map, int lines);
int		revstrncmp(char *compare, char *map_name, int n);
int		is_valid_path(t_map *info);
void	is_map_playable(t_map *info, int x, int y);

/*-- UTILS --*/
int		count_lines(char *map_name);
void	free_matrix(char **map, int lines);
void	free_all(t_map *info);
void	ft_puterror(int error);
char	**get_map(char *map_name, int lines);
char	**copy_map(char **map, int lines);
int		get_p_line(char **map, int lines, t_map *info);
int		get_p_column(char **map, int lines, t_map *info);
int		get_c_number(t_map *info);
t_map	*populate_struct_info(char **map, int lines);

/*-- PMOVES --*/
int		is_e(t_map *info);
int		moves(int keycode, t_map *info);
int		player_up(t_map *info, int line);
int		player_down(t_map *info, int line);
int		player_left(t_map *info, int column);
int		player_right(t_map *info, int column);
void	player_left_helper(t_map *info);
void	player_right_helper(t_map *info);
void	player_up_helper(t_map *info);
void	player_down_helper(t_map *info);
void	new_left_assets(t_map *info);
void	new_right_assets(t_map *info);
void	new_up_assets(t_map *info);
void	new_down_assets(t_map *info);

/*-- DISPLAY FUNC --*/
int		populate_window(t_map *info);
t_img	*populate_img(t_map *info);
void	print_moves(t_map *info);

#endif
