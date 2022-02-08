/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:06:45 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/08 06:07:02 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (check_arg(argc, argv[1]))
		return (1);
	if (init_game(&game, argv[1]))
		return (2);
	game.mlx.mlx_ptr = mlx_init();
	if (game.mlx.mlx_ptr == NULL)
	{
		end_game(&game);
		return (1);
	}
	game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, \
		game.map.columns * IMG_SIZE, game.map.lines * IMG_SIZE, "so_long");
	if (game.mlx.win_ptr == NULL)
	{
		end_game(&game);
		return (1);
	}
	// mlx_hook(game.mlx.win_ptr, KeyPress, KeyPressMask, &key_mapping, &game);
	// mlx_hook(game.mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &game);
	// mlx_loop_hook(game.mlx.mlx_ptr, &load_game, &game);
	mlx_loop(game.mlx.mlx_ptr);
	
	mlx_destroy_window(game.mlx.mlx_ptr, game.mlx.win_ptr);
	mlx_destroy_display(game.mlx.mlx_ptr);
	free(game.mlx.mlx_ptr);
	end_game(&game);
	return (0);
}
