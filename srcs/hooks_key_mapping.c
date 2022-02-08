/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_key_mapping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:10:40 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/08 05:48:31 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int mv_lin, int mv_col, int key);
static int	move_verify(t_game *game, int lin, int col, int key);
static int	valid_key(int key);

int	key_mapping(int	keysym, t_game *game)
{
	int	lin;
	int	col;

	lin = game->pos.y;
	col = game->pos.x;
	if (keysym == ESC || keysym == Q)
		end_game(game);
	// else if (keysym == 'w' || keysym == UP_ARROW)
	// 	lin--;
	// else if (keysym == 'a' || keysym == LEFT_ARROW)
	// 	col--;
	// else if (keysym == 's' || keysym == DOWN_ARROW)
	// 	lin++;
	// else if (keysym == 'd' || keysym == RIGHT_ARROW)
	// 	col++;
	// if (game->game_over == 0)
	// 	move_player(game, lin, col, keysym);
	// //printf("%d\n", keysym);

	return (FALSE);
}

static void	move_player(t_game *game, int mv_lin, int mv_col, int key)
{
	int	x;
	int	y;
	int	valid;
	
	y = game->pos.y;
	x = game->pos.x;
	valid = move_verify(game, mv_lin, mv_col, key);
	if (valid)
	{
		game->moves++;
		game->map.map[y][x] = '0';
		game->map.map[mv_lin][mv_col] = 'P';
		game->pos.y = mv_lin;
		game->pos.x = mv_col;
		load_game(game);
		printf("Moves: %d\n", game->moves);
	}
}

static int	move_verify(t_game *game, int lin, int col, int key)
{
	if (!valid_key(key))
			return (0);
	if (game->map.map[lin][col] == '1')
		return (0);
	else if (game->map.map[lin][col] == 'E' 
		&& game->collected == game->map.check.collectible)
	{
		game->map.map[game->pos.y][game->pos.x] = '0';
		game->game_over = 1;
		return (0);
	}
	else if (game->map.map[lin][col] == 'E')
		return (0);
	if (game->map.map[lin][col] == 'C')
		game->collected++;
	return (1);
	
}

static int	valid_key(int key)
{
	if (key == 'w' || key == 'a' || key == 's' || key != 'd')
		return (TRUE);
	if (key == UP_ARROW || key == DOWN_ARROW \
		|| key == LEFT_ARROW || key != RIGHT_ARROW)
	{
		return (TRUE);
	}
	return (FALSE);
}