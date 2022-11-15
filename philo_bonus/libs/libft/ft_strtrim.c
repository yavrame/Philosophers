/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:45:43 by emarion           #+#    #+#             */
/*   Updated: 2021/10/20 20:30:57 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bi;
	size_t	ei;

	if (!(s1 && set))
		return (NULL);
	bi = 0;
	ei = ft_strlen(s1) - 1;
	while (s1[bi] && ft_strchr(set, s1[bi]))
		bi ++;
	while (s1[ei] && ft_strchr(set, s1[ei]))
	{
		ei --;
		if (ei == 0)
			break ;
	}
	if (bi >= ei)
		return (ft_substr(s1, bi, 0));
	return (ft_substr(s1, bi, ei - bi + 1));
}
