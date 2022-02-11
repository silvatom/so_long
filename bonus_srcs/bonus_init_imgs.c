/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:33:17 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/11 05:59:29 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_map(t_game *game);
static void	init_itens(t_game *game);
static void	init_player(t_game *game);

void	init_imgs(t_game *game)
{
	init_map(game);
	init_itens(game);
	init_player(game);
}

static void	init_map(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx.mlx_ptr, FLOOR, \
		&(game->img.size.x), &(game->img.size.y));
	game->img.wall = mlx_xpm_file_to_image(game->mlx.mlx_ptr, WALL, \
		&(game->img.size.x), &(game->img.size.y));
	game->img.exitc = mlx_xpm_file_to_image(game->mlx.mlx_ptr, EXIT_C, \
		&(game->img.size.x), &(game->img.size.y));
	game->img.exito = mlx_xpm_file_to_image(game->mlx.mlx_ptr, EXIT_O, \
		&(game->img.size.x), &(game->img.size.y));
}

static void	init_itens(t_game *game)
{
	game->img.collect = mlx_xpm_file_to_image(game->mlx.mlx_ptr, \
		COLLECTS, &(game->img.size.x), &(game->img.size.y));
}

static void	init_player(t_game *game)
{
	t_player	player;

	player.up = mlx_xpm_file_to_image(game->mlx.mlx_ptr, P_UP, \
		&(game->img.size.x), &(game->img.size.y));
	player.down = mlx_xpm_file_to_image(game->mlx.mlx_ptr, P_DOWN, \
		&(game->img.size.x), &(game->img.size.y));
	player.right = mlx_xpm_file_to_image(game->mlx.mlx_ptr, P_RIGHT, \
		&(game->img.size.x), &(game->img.size.y));
	player.left = mlx_xpm_file_to_image(game->mlx.mlx_ptr, P_LEFT, \
		&(game->img.size.x), &(game->img.size.y));
	game->img.player = player;
}
