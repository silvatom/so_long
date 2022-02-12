/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:33:39 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/12 06:23:49 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_item(t_game *game, char *rline, int nline);

int	map_check(t_game *game)
{
	if (game->map.lines == 0)
	{
		error_msg("The map is empty!");
		return (TRUE);
	}
	if (game->map.lines < 3)
	{
		error_msg("Invalid number of lines in the map!");
		return (TRUE);
	}
	else if (game->map.columns < 3)
	{
		error_msg("Invalid number of columns!");
		return (TRUE);
	}
	if (game->map.columns == game->map.lines)
	{
		error_msg("Map is not a rectangle");
		return (TRUE);
	}
	return (FALSE);
}

int	column_check(t_game *game, char *map_file)
{
	int		fd;
	int		lin;
	int		invalid;
	char	*rline;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd))
		return (TRUE);
	rline = get_next_line(fd);
	invalid = 0;
	lin = 0;
	while (rline)
	{
		if (check_item(game, rline, lin) != game->map.columns)
		{
			if (!invalid)
				invalid = error_msg("Some lines doesn't match the size!");
		}
		free(rline);
		rline = get_next_line(fd);
		lin++;
	}
	free(rline);
	close(fd);
	if (invalid)
		return (TRUE);
	return (FALSE);
}

int	check_item_count(t_game *game)
{
	if (game->map.invalid)
		return (error_msg("The map has (an) invalid character(s)!"));
	if (game->map.check.players < 1)
		return (error_msg("The map doesn't have a starting point!"));
	if (game->map.check.exit < 1)
		return (error_msg("The map doesn't have an exit!"));
	if (game->map.check.collectible < 1)
		return (error_msg("The map doesn't have collectibles!"));
	if (game->map.check.players > 1)
		return (error_msg("The map has more than 1 player!"));
	if (game->map.check.exit > 1)
		return (error_msg("The map has more than 1 exit!"));
	if (game->map.check.enemy < 1)
		return (error_msg("The map hasn't enemies!"));
	return (FALSE);
}

static int	check_item(t_game *game, char *rline, int nline)
{
	int	col;

	col = 0;
	while (rline[col] != '\n' && rline[col] != '\0')
	{
		if (rline[col] == 'C')
			game->map.check.collectible++;
		else if (rline[col] == 'E')
			game->map.check.exit++;
		else if (rline[col] == 'P')
		{
			game->map.check.players++;
			game->pos.x = col;
			game->pos.y = nline;
		}
		else if (rline[col] == 'F')
			game->map.check.enemy++;
		else if (rline[col] != 'C' && rline[col] != 'E' && rline[col] != 'P'
			&& rline[col] != '1' && rline[col] != '0' && rline[col] != '\n'
			&& rline[col] != 'F')
				game->map.invalid++;
		col++;
	}
	return (col);
}
