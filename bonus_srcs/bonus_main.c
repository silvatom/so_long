/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:33:28 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/11 00:40:27 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (check_arg(argc, argv[1]))
		return (1);
	if (init_game(&game, argv[1]))
		return (2);
	mlx_hook(game.mlx.win_ptr, KeyPress, KeyPressMask, &key_mapping, &game);
	mlx_hook(game.mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, &load_game, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
