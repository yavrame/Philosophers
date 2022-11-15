/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:02:23 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 20:02:54 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

# include "../libs/libft/libft.h"

# define MAX_PHILO_COUNT	200
# define TAKE_FORK			"has taken a fork"
# define EATING				"is eating"
# define SLEEPING			"is sleeping"
# define THINKING			"is thinking"
# define DIED				"died"

typedef struct timeval	t_timeval;

typedef struct s_philo
{
	sem_t		*eating_times_in_child_process;
	pid_t		pid;
	t_timeval	last_eat_time;
	int			eating_times;
}	t_philo;

typedef struct s_values
{
	int			philo_count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			expected_meals_count;
	t_philo		philos[MAX_PHILO_COUNT];
	sem_t		*forks_available;
	pthread_t	life_controller_thread;
	t_timeval	program_start_time;
	pid_t		controller_pid;
	sem_t		*print;
}	t_values;

int		ft_validate_args(int argc, char **argv);
int		ft_init_t_values(int argc, char **argv, t_values *values);
int		ft_processes_create(t_values *values);
int		ft_meal_processes_controller_create(t_values *values);
void	wait_for_ended_process(t_values *values);
int		ft_init_sems(t_values *values);
int		ft_logger(t_values *values, int philo_id, char *log_message);
void	*eating_counter(void *data);
void	ft_run_philo(t_values*values, int philo_num);
void	ft_close_sems(t_values *values);
void	cleaner(t_values *values);
void	ft_kill_all(t_values *util);

#endif