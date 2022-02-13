/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:34:00 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/13 19:30:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	save_map(t_game *game, char *map_file)
{
	char	*rline;
	char	*backup;
	int		fd;
	char	*temp;
	int		i;

	fd = open(map_file, O_RDONLY);
	if (check_fd(fd))
		return (TRUE);
	rline = get_next_line(fd);
	backup = ft_strdup("");
	i = 0;
	while (i++ < game->map.lines)
	{
		temp = ft_strjoin(backup, rline);
		free(rline);
		free(backup);
		backup = temp;
		rline = get_next_line(fd);
	}
	free(rline);
	game->map.map = ft_split(backup, '\n');
	free(backup);
	close(fd);
	return (FALSE);
}
