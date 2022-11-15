/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:14:48 by emarion           #+#    #+#             */
/*   Updated: 2021/10/20 12:12:19 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char)*s1 - (unsigned char)*s2) != 0)
			|| *s1 == '\0' || *s2 == '\0')
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1 ++;
		s2 ++;
		i ++;
	}
	return (0);
}
