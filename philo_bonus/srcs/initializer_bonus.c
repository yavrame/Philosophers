/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:58:57 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 20:01:41 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
	return (0);
}

int	ft_init_sems(t_values *values)
{
	int		i;

	i = 0;
	while (i < values->philo_count)
	{
		values->philos[i].eating_times = 0;
		values->philos[i].eating_times_in_child_process
			= sem_open("eating_sem", O_CREAT, S_IRWXU, 0);
		if (values->philos[i].eating_times_in_child_process == SEM_FAILED)
			return (1);
		i++;
	}
	values->forks_available = sem_open("forks_available", O_CREAT, S_IRWXU,
			values->philo_count);
	if (values->forks_available == SEM_FAILED)
		return (1);
	values->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	if (values->print == SEM_FAILED)
		return (1);
	return (0);
}
