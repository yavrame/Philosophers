/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:53:00 by emarion           #+#    #+#             */
/*   Updated: 2021/10/19 13:45:24 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	if (start > ft_strlen(s))
	{
		mem[i] = '\0';
		return (mem);
	}
	while ((char)s[start + i] != 0 && i < len)
	{
		mem[i] = (char)s[start + i];
		i ++;
	}
	mem[i] = '\0';
	return (mem);
}
