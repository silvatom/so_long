/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:51:07 by anjose-d          #+#    #+#             */
/*   Updated: 2022/02/05 11:30:59 by anjose-d         ###   ########.fr       */
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
