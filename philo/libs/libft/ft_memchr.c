/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:43:39 by emarion           #+#    #+#             */
/*   Updated: 2021/10/23 13:56:47 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*rs;
	size_t			i;

	i = 0;
	rs = (unsigned char *)s;
	while (i < n)
	{
		if (rs[i] == (unsigned char)c)
			return (&rs[i]);
		i ++;
	}
	return (NULL);
}
