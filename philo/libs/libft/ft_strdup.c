/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:40:49 by emarion           #+#    #+#             */
/*   Updated: 2021/10/14 22:41:05 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	size_t	len;

	len = ft_strlen(s1) + 1;
	mem = (char *)malloc(len);
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, len);
	return (mem);
}
