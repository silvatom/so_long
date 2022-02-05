/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:54:30 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/04 23:52:44 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
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

int	column_ncheck(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (i != game->map.columns)
	{
		error_msg("This map isn't a rectangle!");
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_item_count(t_game *game)
{
	if (game->map.invalid)
	{
		error_msg("The map has (an) invalid character(s)!");
		return (TRUE);
	}
	if (game->map.check.players < 1 )
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
