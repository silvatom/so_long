/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:35:00 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/01 23:28:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border_line(char *line);
int	check_border_column(char *line, int map_cols);
int	border_chckr(char *line, int nline, int map_lines, int map_columns);

int	check_borders(t_game *game, char *map_file)
{
	int		fd;
	char	*rline;
	int		nline;
	int		invalid;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd))
		return (TRUE);
	invalid = 0;
	nline = 0;
	while (++nline <= game->map.lines)
	{
		rline = get_next_line(fd);
		if (!invalid)
		{
			if (border_chckr(rline, nline, game->map.lines, game->map.columns))
				invalid = 1;
		}
		free(rline);
	}
	close(fd);
	if (invalid)
		return (TRUE);
	return (FALSE);
}

int	border_chckr(char *line, int nline, int map_lines, int map_columns)
{
	if (nline == 1 || nline == map_lines)
	{
		if (check_border_line(line))
		{
			error_msg("The map is not surrounded by walls!");
			return (TRUE);
		}
	}
	else
	{
		if (check_border_column(line, map_columns))
		{
			error_msg("The map is not surrounded by walls!");
			return (TRUE);
		}
	}
	return (FALSE);
}

int	check_border_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	check_border_column(char *line, int map_cols)
{
	if (line[0] != '1' || line[map_cols - 1] != '1')
		return (TRUE);
	return (FALSE);
}
