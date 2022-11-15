/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:25:59 by emarion           #+#    #+#             */
/*   Updated: 2021/10/20 11:10:13 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!(s1 && s2))
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!mem)
		return (NULL);
	while (++ i < len1)
		mem[i] = s1[i];
	i = -1;
	while (++ i < len2)
		mem[len1 + i] = s2[i];
	mem[len1 + i] = '\0';
	return (mem);
}
