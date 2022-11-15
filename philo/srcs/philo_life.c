/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:11 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 21:54:03 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pthread_mutex_lock(philo->stdout_logger_mutex);
// 	printf("%ld %d %s\n",
// 		ft_find_execution_time(philo), philo->id, log_message);
// 	pthread_mutex_unlock(philo->stdout_logger_mutex);

#include "../includes/philo.h"

static int	ft_sleeping(t_philo *philo)
{
	ft_logger(philo, SLEEPING);
	usleep(philo->sleep_duration * 1000);
	return (0);
}

static void	ft_update_last_time_eat(t_timeval *tv, t_philo *philo)
{
	pthread_mutex_lock(philo->time_mutex);
	tv->tv_usec += philo->meal_duration * 1000;
	if (tv->tv_usec >= 100000)
	{
		tv->tv_sec++;
		tv->tv_usec -= 100000;
	}
	pthread_mutex_unlock(philo->time_mutex);
}

static int	ft_eating(t_philo *philo)
{
	t_fork	*first_fork_to_take;
	t_fork	*next_fork_to_take;

	first_fork_to_take = philo->left_fork ;
	next_fork_to_take = philo->right_fork;
	if (philo->left_fork->id > philo->right_fork->id)
	{
		first_fork_to_take = philo->right_fork;
		next_fork_to_take = philo->left_fork;
	}
	pthread_mutex_lock(&first_fork_to_take->mutex);
	ft_logger(philo, TAKE_FORK);
	pthread_mutex_lock(&next_fork_to_take->mutex);
	ft_logger(philo, TAKE_FORK);
	ft_logger(philo, EATING);
	usleep(philo->meal_duration * 1000);
	pthread_mutex_lock(philo->meals_count_mutex);
	philo->meals_count++;
	pthread_mutex_unlock(philo->meals_count_mutex);
	ft_update_last_time_eat(&philo->last_meal_time, philo);
	pthread_mutex_unlock(&first_fork_to_take->mutex);
	pthread_mutex_unlock(&next_fork_to_take->mutex);
	return (0);
}

static int	ft_thinking(t_philo *philo)
{
	ft_logger(philo, THINKING);
	return (0);
}

void	*ft_philo_life_circle(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
}
