/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:51:07 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/29 22:51:12 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_arg(int argc, char *argv)
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

void error_msg(char *errstr)
{
    ft_putstr("Error: ");
    ft_putstr(errstr);
    ft_putstr("\n");
}