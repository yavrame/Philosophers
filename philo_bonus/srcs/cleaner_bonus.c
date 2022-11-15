/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:01:49 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 20:01:50 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_close_sems(t_values *values)
{
	int	i;

	i = 0;
	while (i < values->philo_count)
	{
		sem_close(values->philos[i].eating_times_in_child_process);
		sem_unlink("eating_sem");
		i++;
	}
	sem_close(values->forks_available);
	sem_close(values->print);
}

void	cleaner(t_values *values)
{
	ft_close_sems(values);
	sem_unlink("forks_available");
	sem_unlink("print");
}

void	ft_kill_all(t_values *util)
{
	int	i;

	i = 0;
	while (i < util->philo_count)
	{
		kill(util->philos[i].pid, SIGKILL);
		i++;
	}
}
