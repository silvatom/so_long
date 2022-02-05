/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:03:53 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/05 11:36:41 by anjose-d         ###   ########.fr       */
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
	if (check_map(game) || column_ncheck(game, map_file))
	 	return (TRUE);
	if (check_borders(game, map_file))
	 	return (TRUE);
	return (FALSE);
}

int	count_lines(t_game *game, char *map_file)
{
	char	*rline;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd))
		return (TRUE);
	rline = get_next_line(fd);
	while (rline)
	{
		game->map.lines++;
		free(rline);
		rline = get_next_line(fd);
	}
	free(rline);
	close(fd);
	return (FALSE);
}
// count lines
	//já verifica estremidades
// count columns
	// verifica cada item na coluns

int	count_columns(t_game *game, char *map_file)
{
	int		fd;
	int		column_s;
	char	*rline;
	char	*temp;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd) || game->map.lines == 0)
		return (TRUE);
	rline = get_next_line(fd);
	while (rline)
	{
		temp = ft_strtrim(rline, "\n");
		column_s = ft_strlen(temp);
		if (column_s > game->map.columns)
			game->map.columns = column_s;
		free(rline);
		free(temp);
		rline = get_next_line(fd);
	}
	free(rline);
	close(fd);
	return (FALSE);
}
