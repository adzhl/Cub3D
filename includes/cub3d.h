/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:46 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/23 07:44:39 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "enum.h"
# include "raycast.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 800
# define TEXTURE_WIDTH 128
# define TEXTURE_HEIGHT 128

// keycodes
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_texture
{
	char		*path;
	void		*img;
	void		*addr;
	int			width;
	int			height;
}				t_texture;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct s_player // New structure for player
{
	double x;
	double y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	char direction; // N, S, E, or W
}				t_player;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_map		map;
	t_ray		ray;
}				t_game;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

// utils.c
bool			is_empty_line(char *line);
void			free_split(char **split);
void			free_texture_path(t_game *game);
void			free_map(t_game *game);
int				element_type(char *line);
bool			clean_and_error(char *line, int fd);

// error.c
void			error_exit(char *message);
void			free_map(t_game *game);
void			cleanup(t_game *game);

// parse.c
void			parse(char *file, t_game *game);
bool			parse_file(char *file, t_game *game);

// parse_utils.c
bool			parse_element(char *line, t_game *game, int element_type);
bool			parse_texture(char **split, t_game *game);
bool			parse_color(char **split, t_game *game);

// parse_map.c
bool			parse_map(char *line, t_game *game);
bool			validate_map(t_game *game);

// get_next_line.c
char			*get_next_line(int fd);

// ft_split_whitespace.c
char			**ft_split_whitespace(char *str);

// init_struct.c
void			init_struct(t_game *game);
void			init_struct_game(t_game *game);
void			init_struct_texture(t_game *game);
void			init_struct_player(t_game *game);
void			init_struct_map_ray(t_game *game);

// init_game.c
void			init_game(t_game *game);
void			init_mlx(t_game *game);

// init_elements.c
void			init_texture(t_game *game);
void			init_player(t_game *game);
//void			find_player(t_game *game);
int				valid_player_char(char c);

// debug.c
void			debug(t_game *game);

// validate_map.c
bool			validate_map_closed(t_game *game);

// validate_map_utils.c
char			**duplicate_map(t_game *game);
bool			validate_fill(char **map, t_point size);

#endif