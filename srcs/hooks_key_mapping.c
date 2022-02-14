/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_key_mapping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:10:40 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/13 20:46:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int mv_lin, int mv_col, int key);
static int	move_verify(t_game *game, int lin, int col, int key);
static int	valid_key(int key);
static void	print_moves(long int nbr, int fd);

int	key_mapping(int keysym, t_game *game)
{
	int	lin;
	int	col;

	lin = game->pos.y;
	col = game->pos.x;
	if (keysym == ESC || keysym == Q || keysym == 'Q')
		end_game(game);
	else if (keysym == W || keysym == UP_ARROW || keysym == 'W')
		lin--;
	else if (keysym == A || keysym == LEFT_ARROW || keysym == 'A')
		col--;
	else if (keysym == S || keysym == DOWN_ARROW || keysym == 'S')
		lin++;
	else if (keysym == D || keysym == RIGHT_ARROW || keysym == 'D')
		col++;
	if (game->game_over == 0)
		move_player(game, lin, col, keysym);
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
		print_moves(game->moves, 1);
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
	if (key == W || key == A || key == S || key == D)
		return (TRUE);
	if (key == UP_ARROW || key == DOWN_ARROW \
		|| key == LEFT_ARROW || key == RIGHT_ARROW)
	{
		return (TRUE);
	}
	if (key == 'W' || key == 'A' || key == 'S' || key == 'D')
		return (TRUE);
	return (FALSE);
}

static void	print_moves(long int nbr, int fd)
{
	ft_putstr("Moves: ");
	ft_putnbr_fd(nbr, fd);
	ft_putstr("\n");
}
