/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:32:45 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/13 06:55:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_arg(int argc, char *argv)
{
	if (argc != 2)
	{
		error_msg("Wrong number of arguments!");
		return (TRUE);
	}
	if (ft_extcheck(argv, ".ber"))
	{
		error_msg("File extension invalid!");
		return (TRUE);
	}
	return (FALSE);
}

int	error_msg(char *errstr)
{
	ft_putstr("Error: ");
	ft_putstr(errstr);
	ft_putstr("\n");
	return (TRUE);
}

int	check_fd(int fd)
{
	if (fd < 0)
	{
		error_msg("Can't open the file to read!");
		return (TRUE);
	}
	return (FALSE);
}

void	delta_time(t_game *game)
{
	game->sprite_cntl.delta_time = time(0) - game->sprite_cntl.init_time + 1;
	if (game->sprite_cntl.delta_time > SPRITES)
		game->sprite_cntl.init_time = time(0);
}

void	print_msg_window(t_game *game)
{
	char	*steps;
	int		y_pos;

	y_pos = (game->map.columns * IMG_SIZE) - IMG_SIZE;
	steps = ft_itoa(game->moves);
	mlx_string_put(game->mlx.mlx_ptr, game->mlx.win_ptr, 
		5, 15, 0xFFFFFF, "MOVES:");
	mlx_string_put(game->mlx.mlx_ptr, game->mlx.win_ptr, 
		45, 15, 0xFFFFFF, steps);
	if (game->died)
		mlx_string_put(game->mlx.mlx_ptr, game->mlx.win_ptr, 
			y_pos, 15, 0xFFFFFF, "YOU DIED!");
	if (game->game_over)
		mlx_string_put(game->mlx.mlx_ptr, game->mlx.win_ptr, 
			y_pos, 15, 0xFFFFFF, "YOU WON!");
	free(steps);
}
