/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:48:19 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/05 12:45:20 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *map_arg)
{
	t_map	map;

	init_struct_map(&map);
	game->map = map;
	if (map_read(game, map_arg))
		return (TRUE);
	if (save_map(game, map_arg))
	 	return (TRUE);
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, \
		game->map.columns * IMG_SIZE, game->map.lines * IMG_SIZE, "so_long");// qual vai primeiro?
	init_imgs(game);
	// mlx_hook keypress
	// mlx_hook click x
	return (FALSE);
}
