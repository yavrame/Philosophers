/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:13:02 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 20:54:32 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static long	ft_find_execution_time(t_philo *philo)
{
	t_timeval	tm;

	gettimeofday(&tm, 0);
	return ((tm.tv_sec - philo->program_start_time.tv_sec) * 1000
		+ (tm.tv_usec - philo->program_start_time.tv_usec) / 1000);
}

void	ft_logger(t_philo *philo, char *log_message)
{
	pthread_mutex_lock(philo->stdout_logger_mutex);
	printf("%ld %d %s\n",
		ft_find_execution_time(philo), philo->id, log_message);
	pthread_mutex_unlock(philo->stdout_logger_mutex);
}
