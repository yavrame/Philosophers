/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:35:59 by emarion           #+#    #+#             */
/*   Updated: 2021/10/08 23:48:18 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ucb;

	ucb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ucb[i] = c;
		i ++;
	}
	return (ucb);
}
