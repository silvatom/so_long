/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:42:50 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/05 11:12:54 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game);
void	init_itens(t_game *game);
void	init_player(t_game *game);

void	init_imgs(t_game *game)
{
	init_map(game);
	init_itens(game);
	init_player(game);
	printf("%d\n", game->map.columns);
}

void	init_map(t_game *game)
{
	game->img.floor->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, FLOOR, \
		&(game->img.floor->size.x), &(game->img.floor->size.y));
	game->img.wall->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, WALL, \
		&(game->img.wall->size.x), &(game->img.wall->size.y));
	game->img.exitc->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, EXIT_C, \
		&(game->img.exitc->size.x), &(game->img.exitc->size.y));
	game->img.exito->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, EXIT_O, \
		&(game->img.wall->size.x), &(game->img.wall->size.y));
}

void	init_itens(t_game *game)
{
	printf("%d\n", game->map.columns);
	// items;
}

void	init_player(t_game *game)
{
	game->img.player->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, P_UP, \
		&(game->img.player->size.x), &(game->img.player->size.y));
}
