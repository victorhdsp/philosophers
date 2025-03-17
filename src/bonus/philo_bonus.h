/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:17:12 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/17 15:58:49 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/wait.h>

# define NUL 0
# define WAIT 1
# define GETTED 2
# define EATED 3
# define SLEEPY 4
# define SLEEPED 5
# define UNHUNGRY 6
# define DEAD 7

typedef long long	t_timestamp;

typedef struct s_system
{
	char			*sem_forks_name;
	sem_t			*forks;
}					t_system;

typedef struct s_table
{
	pid_t			*pid;
	int				philosophers_number;
	int				hungry_size;
	t_timestamp		time_to_eat;
	t_timestamp		time_to_sleep;
	t_timestamp		time_to_die;
}					t_table;

typedef struct s_philosopher
{
	int				index;
	int				current_action;
	t_timestamp		current_time;
	t_timestamp		last_eating;
	int				hungry_size;
}					t_philosopher;

t_timestamp			ft_get_timestamp(void);
void				ft_usleep(int time_in_ms);

int					to_getting_action(sem_t *forks, t_philosopher *philo);
int					to_sleepy_action(sem_t *forks, t_philosopher *philo);
int					to_wait_action(t_philosopher *philo);
int					to_eating_action(t_table table, t_philosopher *philo);
void				to_sleeped_action(t_table table, int *current_action);

long				ft_atol(const char *value);
void				*ft_calloc(int size, int weight);

void				ft_observer_philosopher(t_table table, t_philosopher *philo,
						sem_t *forks);
void				philo_routine(t_table table, sem_t *forks, int index);

#endif