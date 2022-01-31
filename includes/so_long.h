/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:13:50 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/30 23:23:25 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_axis
{
	int	x;
	int	y;
}				t_axis;

typedef struct s_conn
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_conn;

typedef struct s_data
{
	void	*img;
	t_axis	size;
}				t_data;

typedef struct s_draw
{
	t_data	*player;
	t_data	*wall;
	t_data	*floor;
	t_data	*exito;
	t_data	*exitc;
	t_data	*collectible;
}				t_draw;

typedef struct s_map
{
	char	**map;
	int		columns;
	int		lines;
	int		players;
	int		collectables;
}				t_map;

/* MAIN STRUCT */
typedef struct s_game
{
	t_conn	mlx;
	t_map	map;
	t_draw	img;
	int		moves;
	int		game_over;
}				t_game;

/* ARGUMENT AND REGULAR CHECKS */
int		check_arg(int argc, char *argv);
void	error_msg(char *errstr);
int		check_fd(int fd);

/* INIT STRUCTS */
void	init_struct_game(t_game *game);
void	init_struct_map(t_map *map);

/* PRECISA DELA? */
int		init_game(t_game *game, char *map_arg);

/* MAP READING */
int		read_map(t_game *game, char *map_file);

#endif