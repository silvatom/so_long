/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hooks_load_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:33:04 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/11 05:59:05 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_map(t_game *game, int lin, int col);
static void	load_player(t_game *game, int lin, int col);
static void	load_collects(t_game *game, int lin, int col);

int	load_game(t_game *game)
{
	int	lin;
	int	col;

	lin = 0;
	while (game->map.map[lin])
	{
		col = 0;
		while (game->map.map[lin][col])
		{
			if (game->map.map[lin][col] == '1')
				load_map(game, lin, col);
			else if (game->map.map[lin][col] == '0')
				load_map(game, lin, col);
			else if (game->map.map[lin][col] == 'C')
				load_collects(game, lin, col);
			else if (game->map.map[lin][col] == 'E')
				load_map(game, lin, col);
			else if (game->map.map[lin][col] == 'P')
				load_player(game, lin, col);
			col++;
		}
		lin++;
	}
	return (TRUE);
}

static void	load_map(t_game *game, int lin, int col)
{
	if (game->map.map[lin][col] == '1')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
			game->img.wall, col * IMG_SIZE, lin * IMG_SIZE);
	else if (game->map.map[lin][col] == '0')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
			game->img.floor, col * IMG_SIZE, lin * IMG_SIZE);
	else if (game->map.map[lin][col] == 'E'
		&& game->collected != game->map.check.collectible)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img.exitc, col * IMG_SIZE, lin * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img.exito, col * IMG_SIZE, lin * IMG_SIZE);
}

static void	load_player(t_game *game, int lin, int col)
{
	if (game->map.side == 'W' || game->map.side == W \
		|| game->map.side == UP_ARROW)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
			game->img.player.up, col * IMG_SIZE, lin * IMG_SIZE);
	}
	else if (game->map.side == 'D' || game->map.side == D \
		|| game->map.side == RIGHT_ARROW)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
			game->img.player.right, col * IMG_SIZE, lin * IMG_SIZE);
	}
	else if (game->map.side == 'A' || game->map.side == A \
		|| game->map.side == LEFT_ARROW)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
			game->img.player.left, col * IMG_SIZE, lin * IMG_SIZE);
	}
	else if (game->map.side == 'S' || game->map.side == S \
		|| game->map.side == DOWN_ARROW)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
		game->img.player.down, col * IMG_SIZE, lin * IMG_SIZE);
	}
}

static void	load_collects(t_game *game, int lin, int col)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, \
		game->img.collect, col * IMG_SIZE, lin * IMG_SIZE);
}
