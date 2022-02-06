/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:48:26 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/06 21:22:26 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct_game(t_game *game);

void	init_struct_map(t_game *game)
{
	game->map.columns = 0;
	game->map.lines = 0;
	game->map.invalid = 0;
	game->map.check.collectible = 0;
	game->map.check.exit = 0;
	game->map.check.players = 0;
	init_struct_game(game);
}

static void	init_struct_game(t_game *game)
{
	game->moves = 0;
	game->game_over = 0;
	game->collected = 0;
	game->pos.x = 0;
	game->pos.y = 0;
}
