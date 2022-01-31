/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:03:53 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/30 23:19:28 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	count_lines(t_game *game, char *map_file);
int	count_columns(t_game *game, char *map_file);

int	read_map(t_game *game, char *map_file)
{
	if (count_lines(game, map_file) || count_columns(game, map_file))
		return (TRUE);
	// while ((rline = get_next_line(fd)))
	// {
	// 	printf("%s", rline);
	// 	free(rline);
	// }
	// free(rline);
	return (FALSE);
}

int	count_lines(t_game *game, char *map_file)
{
	char	*rline;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd))
		return (TRUE);
	while ((rline = get_next_line(fd)))
	{
		game->map.lines++;
		free(rline);
	}
	close(fd);
	free(rline);
	if (game->map.lines > 2)
		return (FALSE);
	else
	{
		error_msg("Invalid number of lines in the map!");
		return (TRUE);
	}
}
// count lines
	//já verifica estremidades
// count columns
	// verifica cada item na coluns

int	count_columns(t_game *game, char *map_file)
{
	char	*fline;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd))
		return (TRUE);
	fline = get_next_line(fd);
	game->map.columns = ft_strlen(fline);
	free(fline);
	while ((fline = get_next_line(fd)))
	{
		if (ft_strlen(fline) != game->map.columns)
		{
			free(fline);
			error_msg("Different number of columns!");
			return (TRUE);
		}
		free(fline);
	}
	free(fline);
	close(fd);
	if (game->map.columns < 3)
		error_msg("Invalid number of columns!");
	if (game->map.columns == game->map.lines)
		error_msg("Map is not a rectangle");
	return (FALSE);
}
