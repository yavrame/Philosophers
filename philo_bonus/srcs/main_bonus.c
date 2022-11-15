/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:57:27 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 19:57:40 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	wait_for_ended_process(t_values *values)
{
	pid_t	died_philo_pid;
	int		i;

	died_philo_pid = waitpid(-1, 0, 0);
	if (values->controller_pid)
		kill(values->controller_pid, SIGKILL);
	i = 0;
	while (i < values->philo_count)
	{
		if (values->philos[i].pid != died_philo_pid)
			kill(values->philos[i].pid, SIGKILL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_values	values;

	if (ft_validate_args(argc, argv))
		return (1);
	if (ft_init_t_values(argc, argv, &values))
		return (1);
	if (ft_init_sems(&values))
		return (1);
	if (ft_processes_create(&values))
		return (1);
	if (ft_meal_processes_controller_create(&values))
		return (1);
	wait_for_ended_process(&values);
	cleaner(&values);
	return (0);
}
