/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:53:40 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/05 16:23:39 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_map(t_game *game, int lin, int col);
static void	load_player(t_game *game, int lin, int col);
static void	load_collects(t_game *game, int lin, int col);

int		load_game(t_game *game)
{
	int	lin;
	int	col;

	lin = 0;
	while (game->map.map[lin])
	{
		col = 0;
		while (game->map.map[lin][col])
		{
			if (game->map.map[lin][col] == '1')
				load_map(game, lin, col);
			else if (game->map.map[lin][col] == '0')
				load_map(game, lin, col);
			else if (game->map.map[lin][col] == 'C')
				load_collects(game, lin, col);
			else if (game->map.map[lin][col] == 'E')
				load_map(game, lin, col);
			else if (game->map.map[lin][col] == 'P')
				load_player(game, lin, col);
			col++;
		}
		lin++;
	}
	return (TRUE); // why return 1?
}

static void	load_map(t_game *game, int lin, int col)
{
	if (game->map.map[lin][col] == '1')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img.wall->img, col * IMG_SIZE, lin * IMG_SIZE);
	else if (game->map.map[lin][col] == '0')
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img.floor->img, col * IMG_SIZE, lin * IMG_SIZE);
	else if (game->map.map[lin][col] == 'E'
		&& game->collected != game->map.check.collectible)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img.exito->img, col * IMG_SIZE, lin * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->img.exitc->img, col * IMG_SIZE, lin * IMG_SIZE);
}

static void	load_player(t_game *game, int lin, int col)
{
	// player
}

static void	load_collects(t_game *game, int lin, int col)
{
	// collectables
}

