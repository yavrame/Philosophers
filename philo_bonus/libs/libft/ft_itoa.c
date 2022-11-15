/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:03:47 by emarion           #+#    #+#             */
/*   Updated: 2021/10/20 21:10:39 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_str_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static char	*ft_line_filling(int n, size_t len, size_t sign, char *res)
{
	size_t	tmp_len;

	tmp_len = len;
	if (sign)
		res[0] = '-';
	while (n != 0)
	{
		res[len + sign - 1] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	res[tmp_len + sign] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	size_t		len;
	size_t		sign;
	char		*res;

	len = ft_find_str_len(n);
	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	res = malloc(sizeof(char) * (len + sign + 1));
	if (!res)
		return (NULL);
	return (ft_line_filling(n, len, sign, res));
}
