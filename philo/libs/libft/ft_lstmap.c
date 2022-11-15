/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:17:56 by emarion           #+#    #+#             */
/*   Updated: 2021/10/21 15:18:01 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_lst;
	t_list	*new_elem;

	(void) del;
	res_lst = NULL;
	while (lst)
	{	
		new_elem = ft_lstnew(f(lst -> content));
		if (!new_elem)
			return (NULL);
		ft_lstadd_back(&res_lst, new_elem);
		lst = lst -> next;
	}
	return (res_lst);
}
