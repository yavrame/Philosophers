/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:58:17 by emarion           #+#    #+#             */
/*   Updated: 2022/06/24 21:47:18 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include "../libs/libft/libft.h"

# define MAX_PHILO_COUNT	200
# define TAKE_FORK			"has taken a fork"
# define EATING				"is eating"
# define SLEEPING			"is sleeping"
# define THINKING			"is thinking"
# define DIED				"died"

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_fork
{
	int		id;
	t_mutex	mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			meals_count;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_mutex		*stdout_logger_mutex;
	t_mutex		check_died_philo_mutex;
	long int	meal_duration;
	long int	sleep_duration;
	t_timeval	last_meal_time;
	t_timeval	program_start_time;
	t_mutex		*time_mutex;
	t_mutex		*meals_count_mutex;
}	t_philo;

typedef struct s_values
{
	int			philo_count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			expected_meals_count;
	t_mutex		stdout_mutex;
	t_timeval	program_start_time;
	int			philos_have_eaten;
	t_mutex		time_mutex;
	t_mutex		meals_count_mutex;
}	t_values;

int		ft_validate_args(int argc, char **argv);
int		ft_init_t_values(int argc, char **argv, t_values *values);
int		ft_init_t_fork_array(t_fork *t_fork_array, t_values *values);
int		ft_init_t_phil_array(t_philo *philo, t_fork *fork, t_values *values);
int		ft_philo_threads_create(t_philo *philo, t_values *values);
int		ft_threads_controller(t_fork *forks, t_philo *philo, t_values *values);
void	*ft_philo_life_circle(void *data);
void	ft_logger(t_philo *philo, char *log_message);
int		ft_init_t_fork_array(t_fork *t_fork_array, t_values *values);
int		ft_mutexes_destroy(t_fork *forks, t_values *values);
int		ft_init_t_phil_array(t_philo *philo, t_fork *fork, t_values *values);
#endif