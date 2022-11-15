/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:12:46 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 21:47:01 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo		t_phil_array[MAX_PHILO_COUNT];
	t_fork		t_fork_array[MAX_PHILO_COUNT];
	t_values	values;

	if (ft_validate_args(argc, argv))
		return (1);
	if (ft_init_t_values(argc, argv, &values))
		return (1);
	if (ft_init_t_fork_array(t_fork_array, &values))
		return (1);
	if (ft_init_t_phil_array(t_phil_array, t_fork_array, &values))
		return (1);
	if (ft_philo_threads_create(t_phil_array, &values))
		return (1);
	return (ft_threads_controller(t_fork_array, t_phil_array, &values));
}
