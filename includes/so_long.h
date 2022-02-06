/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:13:50 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/06 06:22:13 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define TRUE 1
# define FALSE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define IMG_SIZE 64


# define P_UP "./imgs/player/p_down.xpm"

# define EXIT_O "./imgs/exit/opened_exit.xpm"
# define EXIT_C "./imgs/exit/closed_exit.xpm"

# define ENEMY_1 "./imgs/enemy/enemy1.xpm"
# define ENEMY_2 "./imgs/enemy/enemy2.xpm"

# define FLOOR "./imgs/wall/wall.xpm"
# define WALL "./imgs/floor/floor.xpm"
# define COLLECTS "./imgs/collects/collect.xpm"



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

typedef struct s_check
{
	int	collectible;
	int	exit;
	int	players;
}				t_check;

typedef struct s_draw
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*exito;
	void	*exitc;
	void	*collect;
	t_axis	size;	
}				t_draw;

typedef struct s_map
{
	char	**map;
	int		columns;
	int		lines;
	t_check	check;
	int		invalid;
}				t_map;

/* MAIN STRUCT */
typedef struct s_game
{
	t_conn	mlx;
	t_map	map;
	t_draw	img;
	int		moves;
	int		collected;
	int		game_over;
}				t_game;

/* ARGUMENT AND REGULAR CHECKS */
int		check_arg(int argc, char *argv);
int		error_msg(char *errstr);
int		check_fd(int fd);

/* INIT STRUCTS */
void	init_struct_game(t_game *game);
void	init_struct_map(t_map *map);
void	init_imgs(t_game *game);

/* MAIN FUNCTION */
int		init_game(t_game *game, char *map_arg);

/* MAP READING */
int		map_read(t_game *game, char *map_file);

/* MAP CHECK */
int		map_check(t_game *game);
int		column_ncheck(t_game *game, char *map_file);
int		check_item_count(t_game *game);
void	check_item(t_game *game, char c);
int		check_borders(t_game *game, char *map_file);

/* MAP SAVING AND ALLOCATING */
int		save_map(t_game *game, char *map_file);

/* FREE ALLOCATIONS */
void	end_game(t_game *game);

/* HOOKS */
int		load_game(t_game *game);

#endif