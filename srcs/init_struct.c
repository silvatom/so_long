/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:48:26 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/30 23:17:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_map(t_map *map)
{
	map->columns = 0;
	map->lines = 0;
	map->players = 0;
	map->collectables = 0;
}

void	init_struct_game(t_game *game)
{
	game->moves = 0;
	game->game_over = 0;
}
