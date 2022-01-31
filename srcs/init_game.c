/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:48:19 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/30 23:17:39 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *map_arg)
{
	t_map	map;

	init_struct_map(&map);
	game->map = map;
	if (read_map(game, map_arg))
		return (TRUE); //read and check
	//save_map | allocate and save
	return (FALSE);
}
