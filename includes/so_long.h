/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:13:50 by anjose-d          #+#    #+#             */
/*   Updated: 2022/01/29 23:13:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"

# define TRUE 1
# define FALSE 0

/* CHECK ARGUMENTS */
int		check_arg(int argc, char *argv);
void	error_msg(char *errstr);

#endif