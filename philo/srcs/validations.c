/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:10:42 by emarion           #+#    #+#             */
/*   Updated: 2022/06/15 23:10:55 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_validate_args(int argc, char **argv)
{
	int		i;
	char	*arg_str;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	else
	{
		while (i < argc)
		{
			arg_str = argv[i];
			while (*arg_str)
			{
				if (*arg_str < '0' || *arg_str > '9')
					return (1);
				arg_str ++;
			}
			i++;
		}
	}
	return (0);
}
