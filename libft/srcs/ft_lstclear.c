/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:03:21 by anjose-d          #+#    #+#             */
/*   Updated: 2021/08/07 21:03:24 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*old_elem;

	if (!del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		del(tmp->content);
		old_elem = tmp;
		tmp = old_elem->next;
		free(old_elem);
	}
	*lst = NULL;
}
