/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:00:57 by emarion           #+#    #+#             */
/*   Updated: 2021/10/14 16:01:54 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1) - *((unsigned char *)s2) != 0)
		{
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		}
		s1 ++;
		s2 ++;
		i ++;
	}
	return (0);
}
