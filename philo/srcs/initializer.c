/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:14:12 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 21:23:25 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_t_values(int argc, char **argv, t_values *values)
{
	values->philo_count = ft_atoi(argv[1]);
	values->time_to_die = ft_atoi(argv[2]);
	values->time_to_eat = ft_atoi(argv[3]);
	values->time_to_sleep = ft_atoi(argv[4]);
	values->expected_meals_count = -1;
	if (argc == 6)
		values->expected_meals_count = ft_atoi(argv[5]);
	gettimeofday(&values->program_start_time, 0);
	if (pthread_mutex_init(&values->stdout_mutex, 0))
		return (1);
	if (pthread_mutex_init(&values->time_mutex, 0))
		return (1);
	if (pthread_mutex_init(&values->meals_count_mutex, 0))
		return (1);
	return (0);
}

int	ft_init_t_fork_array(t_fork *t_fork_array, t_values *values)
{
	int	i;
	int	forks_count;

	i = 0;
	forks_count = values->philo_count;
	while (i < forks_count)
	{
		t_fork_array[i].id = i + 1;
		if (pthread_mutex_init(&t_fork_array[i].mutex, 0))
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_t_phil_array(t_philo *philo, t_fork *fork, t_values *values)
{
	int			i;

	i = 0;
	while (i < values->philo_count)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = fork + i;
		philo[i].time_mutex = &values->time_mutex;
		philo[i].meals_count_mutex = &values->meals_count_mutex;
		if (i == values->philo_count - 1)
			philo[i].right_fork = fork;
		else
			philo[i].right_fork = fork + i + 1;
		philo[i].stdout_logger_mutex = &values->stdout_mutex;
		if (pthread_mutex_init(&philo[i].check_died_philo_mutex, 0))
			return (1);
		philo[i].meals_count = 0;
		philo[i].meal_duration = values->time_to_eat;
		philo[i].sleep_duration = values->time_to_sleep;
		philo[i].program_start_time = values->program_start_time;
		gettimeofday(&philo[i].last_meal_time, 0);
		i ++;
	}
	return (0);
}
