/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:51:07 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/30 22:53:59 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	error_msg(char *errstr)
{
	ft_putstr("Error: ");
	ft_putstr(errstr);
	ft_putstr("\n");
}

int	check_fd(int fd)
{
	if (fd < 0)
	{
		error_msg("Erro ao abrir para leitura o arquivo!");
		return (TRUE);
	}
	return (FALSE);
}
