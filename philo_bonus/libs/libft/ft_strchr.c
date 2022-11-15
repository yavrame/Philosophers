/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:20:29 by emarion           #+#    #+#             */
/*   Updated: 2021/10/13 23:13:42 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*rs;

	rs = (char *)s;
	while (*rs)
	{
		if (*rs == c)
			return (rs);
		rs ++;
	}
	if (c == '\0')
		return (rs);
	return ((void *)0);
}
