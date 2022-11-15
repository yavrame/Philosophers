/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:55:13 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 19:57:10 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*life_controller(void *data)
{
	t_timeval	current_time;
	t_values	*values;

	values = (t_values *) data;
	while (1)
	{
		gettimeofday(&current_time, 0);
		if ((current_time.tv_sec - values->philos[values->philo_count]
				.last_eat_time.tv_sec) * 1000
			+ (current_time.tv_usec - values->philos[values->philo_count]
				.last_eat_time.tv_usec) / 1000
			>= values->time_to_die)
		{
			ft_logger(values, values->philo_count, DIED);
			exit(1);
		}
		usleep(500);
	}
}

void	ft_run_philo(t_values *values, int philo_num)
{
	values->philo_count = philo_num;
	gettimeofday(&values->philos[philo_num].last_eat_time, 0);
	pthread_create(&values->life_controller_thread, 0, life_controller, values);
	pthread_detach(values->life_controller_thread);
	while (1)
	{
		sem_wait(values->forks_available);
		ft_logger(values, philo_num, TAKE_FORK);
		sem_wait(values->forks_available);
		ft_logger(values, philo_num, TAKE_FORK);
		ft_logger(values, philo_num, EATING);
		sem_post(values->philos[philo_num].eating_times_in_child_process);
		usleep(values->time_to_eat * 1000);
		gettimeofday(&values->philos[philo_num].last_eat_time, 0);
		sem_post(values->forks_available);
		sem_post(values->forks_available);
		ft_logger(values, philo_num, SLEEPING);
		usleep(values->time_to_sleep * 1000);
		ft_logger(values, philo_num, THINKING);
	}
}
