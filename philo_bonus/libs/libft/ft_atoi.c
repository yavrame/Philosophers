/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:13:44 by emarion           #+#    #+#             */
/*   Updated: 2021/10/20 20:22:17 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_check_space(char *str)
{
	if (*str == ' '
		|| *str == '\f'
		|| *str == '\n'
		|| *str == '\r'
		|| *str == '\t'
		|| *str == '\v')
		return (true);
	else
		return (false);
}

static bool	ft_check_digit(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (true);
	else
		return (false);
}

static int	ft_find_result(char *rstr, int sign)
{
	long	result;

	result = 0;
	while (ft_check_digit(rstr))
	{
		result = result * 10 + (*rstr - '0');
		if (result * sign < -2147483648)
			return (0);
		else if (result * sign > 2147483647)
			return (-1);
		rstr ++;
	}
	return ((int)(result * sign));
}

int	ft_atoi(const char *str)
{	
	int		sign;
	char	*rstr;

	rstr = (char *)str;
	sign = 1;
	while (ft_check_space(rstr))
		rstr ++;
	if (*rstr == '-')
	{
		sign = -1;
		rstr ++;
	}
	else if (*rstr == '+')
		rstr ++;
	return (ft_find_result(rstr, sign));
}
