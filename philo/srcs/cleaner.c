/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:14:24 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 21:58:05 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_mutexes_destroy(t_fork *forks, t_values *values)
{
	int	i;

	i = 0;
	usleep(500);
	while (i < values->philo_count)
	{
		forks[i].id = i + 1;
		if (pthread_mutex_destroy(&forks[i].mutex))
			return (-1);
	}
	pthread_mutex_destroy(&values->stdout_mutex);
	return (0);
}
