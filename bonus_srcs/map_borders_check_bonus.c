/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_borders_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:33:34 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/13 07:08:30 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_border_line(char *line);
static int	check_border_column(char *line, int map_cols);
static int	border_chckr(char *line, int nline, t_game *game);

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
			invalid += border_chckr(rline, nline, game);
		free(rline);
	}
	rline = get_next_line(fd);
	free(rline);
	close(fd);
	if (invalid)
		return (TRUE);
	return (FALSE);
}

static int	border_chckr(char *line, int nline, t_game *game)
{
	if (nline == 1 || nline == game->map.lines)
	{
		if (check_border_line(line))
		{
			error_msg("The map is not surrounded by walls!");
			return (TRUE);
		}
	}
	else
	{
		if (check_border_column(line, game->map.columns))
		{
			error_msg("The map is not surrounded by walls!");
			return (TRUE);
		}
	}
	return (FALSE);
}

static int	check_border_line(char *line)
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

static int	check_border_column(char *line, int map_cols)
{
	if (line[0] != '1' || line[map_cols - 1] != '1')
		return (TRUE);
	return (FALSE);
}
