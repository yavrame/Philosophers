/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:37:53 by emarion           #+#    #+#             */
/*   Updated: 2021/10/21 11:38:44 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lstlen;
	t_list	*ilst;

	if (!lst)
		return (0);
	lstlen = 1;
	ilst = lst;
	while (ilst->next)
	{
		ilst = ilst->next;
		lstlen ++;
	}
	return (lstlen);
}
