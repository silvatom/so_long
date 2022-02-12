/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:33:23 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/12 06:02:41 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_struct_game(t_game *game);

void	init_struct_map(t_game *game)
{
	t_map	map;

	map.columns = 0;
	map.lines = 0;
	map.invalid = 0;
	map.check.collectible = 0;
	map.check.exit = 0;
	map.check.players = 0;
	map.check.enemy = 0;
	game->map = map;
	game->map.side = S;
	init_struct_game(game);
}

static void	init_struct_game(t_game *game)
{
	game->moves = 0;
	game->game_over = 0;
	game->died = 0;
	game->collected = 0;
	game->pos.x = 0;
	game->pos.y = 0;
}
