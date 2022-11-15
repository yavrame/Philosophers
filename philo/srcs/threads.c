/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:00 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 21:58:03 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_philo_threads_create(t_philo *philo, t_values *values)
{
	int			i;
	pthread_t	pthread_id;

	i = 0;
	while (i < values->philo_count)
	{
		if (pthread_create(&pthread_id, 0, ft_philo_life_circle, &(philo[i])))
			return (1);
		pthread_detach(pthread_id);
		i++;
	}
	return (0);
}

static int	ft_check_philo_died(t_philo *philo, t_values *values)
{
	t_timeval	current_time;

	gettimeofday(&current_time, 0);
	pthread_mutex_lock(&philo->check_died_philo_mutex);
	pthread_mutex_lock(philo->time_mutex);
	if ((current_time.tv_sec - philo->last_meal_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->last_meal_time.tv_usec + 500) / 1000
		>= values->time_to_die)
	{
		pthread_mutex_unlock(&philo->check_died_philo_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->time_mutex);
	pthread_mutex_unlock(&philo->check_died_philo_mutex);
	return (0);
}

int	ft_threads_controller(t_fork *forks, t_philo *philo, t_values *values)
{
	int	i;

	while (1)
	{
		i = 0;
		values->philos_have_eaten = 1;
		while (i < values->philo_count)
		{
			pthread_mutex_lock(philo->meals_count_mutex);
			if (values->expected_meals_count == -1
				|| philo[i].meals_count < values->expected_meals_count)
				values->philos_have_eaten = 0;
			pthread_mutex_unlock(philo->meals_count_mutex);
			if (ft_check_philo_died(&philo[i], values))
			{
				ft_logger(&philo[i], DIED);
				ft_mutexes_destroy(forks, values);
				return (1);
			}
			i ++;
		}
		if (values->philos_have_eaten)
			return (0);
	}
}
