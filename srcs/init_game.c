/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:48:19 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/13 20:08:01 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *map_arg)
{
	init_struct_map(game);
	if (map_read(game, map_arg))
		return (TRUE);
	if (save_map(game, map_arg))
		return (TRUE);
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
	{
		end_game(game);
		return (1);
	}
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, \
		game->map.columns * IMG_SIZE, game->map.lines * IMG_SIZE + 15,
			GAME_NAME);
	if (game->mlx.win_ptr == NULL)
	{
		end_game(game);
		return (1);
	}
	init_imgs(game);
	return (FALSE);
}
