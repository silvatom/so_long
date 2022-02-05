/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:54:30 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/05 12:40:47 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	column_ncheck(t_game *game, char *map_file)
{
	int		fd;
	int		i;
	char	*rline;
	int		invalid;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd))
		return (TRUE);
	rline = get_next_line(fd);
	invalid = 0;
	while (rline)
	{
		i = 0;
		while (rline[i] != '\n' && rline[i] != '\0')
			check_item(game, rline[i++]);
		if (i != game->map.columns)
			invalid = error_msg("Some lines doesn't match the size!");
		free(rline);
		rline = get_next_line(fd);
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
	{
		error_msg("The map has (an) invalid character(s)!");
		return (TRUE);
	}
	if (game->map.check.players < 1)
	{
		error_msg("The map doesn't have a starting point!");
		return (TRUE);
	}
	if (game->map.check.exit < 1)
	{
		error_msg("The map doesn't have an exit!");
		return (TRUE);
	}
	if (game->map.check.collectible < 1)
	{
		error_msg("The map doesn't have collectibles!");
		return (TRUE);
	}
	return (FALSE);
}

void	check_item(t_game *game, char c)
{
	if (c == 'C')
		game->map.check.collectible++;
	else if (c == 'E')
		game->map.check.exit++;
	else if (c == 'P')
		game->map.check.players++;
	else if (c != 'C' && c != 'E' && c != 'P'
		&& c != '1' && c != '0' && c != '\n')
			game->map.invalid++;
}
