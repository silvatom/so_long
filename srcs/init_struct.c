/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:48:26 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/06 04:18:43 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_map(t_map *map)
{
	map->columns = 0;
	map->lines = 0;
	map->invalid = 0;
	map->check.collectible = 0;
	map->check.exit = 0;
	map->check.players = 0;
}

void	init_struct_game(t_game *game)
{
	game->moves = 0;
	game->game_over = 0;
}
