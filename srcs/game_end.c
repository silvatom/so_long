/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:12:25 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/08 06:05:49 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_map(t_game *game);
static void	destroy_imgs(t_game *game);

int	end_game(t_game *game)
{
	destroy_map(game);
	// destroy_imgs(game);
	// mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	// mlx_destroy_display(game->mlx.mlx_ptr);
	// mlx_loop_end(game->mlx.mlx_ptr);
	// free(game->mlx.mlx_ptr);
	// free(game->mlx.win_ptr);
	// free(game->mlx.mlx_ptr);
	// free(game->mlx.win_ptr);
	return (FALSE);
}

static void	destroy_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.lines)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

static void	destroy_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.collect);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.exitc);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.exito);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.floor);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.player);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.wall);
}
