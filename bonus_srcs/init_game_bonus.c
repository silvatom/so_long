/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:33:11 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/13 20:06:07 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		game->map.columns * IMG_SIZE, (game->map.lines * IMG_SIZE) + STRIPE,
			GAME_NAME);
	if (game->mlx.win_ptr == NULL)
	{
		end_game(game);
		return (1);
	}
	init_imgs(game);
	return (FALSE);
}
