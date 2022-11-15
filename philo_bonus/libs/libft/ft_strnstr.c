/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:38:52 by emarion           #+#    #+#             */
/*   Updated: 2021/10/14 17:39:39 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[h] && h < len)
	{
		n = 0;
		while (haystack[h + n] && needle[n] && haystack[h + n] == needle[n]
			&& (h + n) < len)
		{
			n ++;
			if (!needle[n])
				return ((char *)haystack + h);
		}
		h ++;
	}
	return (0);
}
