/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 05:45:32 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/11 05:50:46 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysymdef.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define IMG_SIZE 64

# define P_DOWN "./imgs/player/p_down.xpm"
# define P_UP "./imgs/player/p_up.xpm"
# define P_RIGHT "./imgs/player/p_right.xpm"
# define P_LEFT "./imgs/player/p_left.xpm"

# define EXIT_O "./imgs/exit/opened_exit.xpm"
# define EXIT_C "./imgs/exit/closed_exit.xpm"
# define ENEMY_1 "./imgs/enemy/enemy1.xpm"
# define ENEMY_2 "./imgs/enemy/enemy2.xpm"
# define FLOOR "./imgs/map/floor.xpm"
# define WALL "./imgs/map/wall.xpm"
# define COLLECTS "./imgs/collects/collect.xpm"

/* KEYS */
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307

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

typedef struct s_player
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}				t_player;

typedef struct s_draw
{
	t_player	player;
	void		*wall;
	void		*floor;
	void		*exito;
	void		*exitc;
	void		*collect;
	t_axis		size;	
}				t_draw;

typedef struct s_map
{
	char	**map;
	int		columns;
	int		lines;
	t_check	check;
	int		invalid;
	int		side;
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
	t_axis	pos;
}				t_game;

/* ARGUMENT AND REGULAR CHECKS */
int		check_arg(int argc, char *argv);
int		error_msg(char *errstr);
int		check_fd(int fd);

/* INIT STRUCTS */
void	init_struct_map(t_game *game);
void	init_imgs(t_game *game);

/* MAIN FUNCTION */
int		init_game(t_game *game, char *map_arg);

/* MAP READING */
int		map_read(t_game *game, char *map_file);

/* MAP CHECK */
int		map_check(t_game *game);
int		column_check(t_game *game, char *map_file);
int		check_item_count(t_game *game);
int		check_borders(t_game *game, char *map_file);

/* MAP SAVING AND ALLOCATING */
int		save_map(t_game *game, char *map_file);

/* FREE ALLOCATIONS */
int		end_game(t_game *game);

/* HOOKS */
int		load_game(t_game *game);
int		key_mapping(int keysym, t_game *game);

#endif