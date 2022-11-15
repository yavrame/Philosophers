/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:48:05 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 19:54:26 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	check_if_ate_enough(t_philo *philo,
								int philo_count, int eating_times)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		if (philo[i].eating_times < eating_times)
			return (0);
		i++;
	}
	return (1);
}

void	*eating_counter(void *data)
{
	t_values	*values;
	int			i;

	values = data;
	while (1)
	{
		i = 0;
		while (i < values->philo_count)
		{
			sem_wait(values->philos[i].eating_times_in_child_process);
			values->philos[i].eating_times++;
			if (check_if_ate_enough(values->philos, values->philo_count,
					values->expected_meals_count))
			{
				ft_kill_all(values);
				exit(0);
			}
			i++;
		}
	}
}

int	ft_processes_create(t_values *values)
{
	int	i;

	i = 0;
	while (i < values->philo_count)
	{
		values->philos[i].pid = fork();
		if (values->philos[i].pid < 0)
			return (1);
		else if (values->philos[i].pid == 0)
			ft_run_philo(values, i);
		i++;
	}
	return (0);
}

int	ft_meal_processes_controller_create(t_values *values)
{
	if (values->expected_meals_count != -1)
	{
		values->controller_pid = fork();
		if (values->controller_pid < 0)
			return (1);
		else if (values->controller_pid == 0)
			eating_counter(values);
	}
	return (0);
}
