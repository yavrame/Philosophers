/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:30:09 by emarion           #+#    #+#             */
/*   Updated: 2021/10/21 14:30:10 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next_lst;
	t_list	*cur_lst;

	cur_lst = lst;
	while (cur_lst)
	{
		next_lst = cur_lst -> next;
		f(cur_lst -> content);
		cur_lst = next_lst;
	}
}
