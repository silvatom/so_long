/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:12:25 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/04 23:40:14 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game);
void	close_conn(t_game *game);
void	destroy_imgs(t_game *game);

void	end_game(t_game *game)
{
	destroy_map(game);
	//close_conn(game);
	destroy_imgs(game);
}

void	destroy_map(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.lines)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

void	close_conn(t_game *game)
{
	free(game->mlx.mlx_ptr);
	free(game->mlx.win_ptr);
}

void	destroy_imgs(t_game *game)
{
	//free(game->img.collectible->img);
	free(game->img.wall->img);
	free(game->img.floor->img);
	free(game->img.exitc->img);
	free(game->img.exito->img);
	free(game->img.player->img);
}
