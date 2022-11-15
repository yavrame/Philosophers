/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:57:56 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 19:58:45 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long	ft_find_execution_time(t_values *values)
{
	t_timeval	tm;

	gettimeofday(&tm, 0);
	return ((tm.tv_sec - values->program_start_time.tv_sec) * 1000
		+ (tm.tv_usec - values->program_start_time.tv_usec) / 1000);
}

int	ft_logger(t_values *values, int philo_id, char *log_message)
{
	sem_wait(values->print);
	printf("%ld %d %s\n", ft_find_execution_time(values),
		philo_id, log_message);
	sem_post(values->print);
	return (0);
}
