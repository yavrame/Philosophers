/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:21:03 by emarion           #+#    #+#             */
/*   Updated: 2021/10/21 14:21:27 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_lst;
	t_list	*cur_lst;

	cur_lst = *lst;
	while (cur_lst)
	{
		next_lst = cur_lst -> next;
		del(cur_lst -> content);
		free(cur_lst);
		cur_lst = next_lst;
	}
	*lst = NULL;
}
