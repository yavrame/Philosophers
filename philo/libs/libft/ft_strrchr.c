/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:48:43 by emarion           #+#    #+#             */
/*   Updated: 2021/10/14 12:48:57 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rs;
	char	*res;

	res = 0;
	rs = (char *)s;
	while (*rs)
	{
		if (*rs == c)
			res = rs;
		rs ++;
	}
	if (c == '\0')
		return (rs);
	return (res);
}
