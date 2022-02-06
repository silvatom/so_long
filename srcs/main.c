/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:06:45 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/06 04:51:41 by anjose-d         ###   ########.fr       */
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
	//mlx_hook teclas apertadas
	//mlx_hook fechar janela
	mlx_loop_hook(game.mlx.mlx_ptr, &load_game, &game);
	mlx_loop(game.mlx.mlx_ptr);
	// 	mlx_loop(game.mlx.mlx_ptr);

	end_game(&game);



	return (0);
}
