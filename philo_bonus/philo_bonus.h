/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:17:12 by vide-sou          #+#    #+#             */
/*   Updated: 2025/04/14 10:13:06 by vide-sou         ###   ########.fr       */
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
# include <sys/wait.h>
# include <unistd.h>
# include <pthread.h>

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
	char			*start_timestamp;
	char			*sem_forks_name;
	sem_t			*forks;
	char			*sem_print_name;
	sem_t			*prints;
}					t_system;

typedef struct s_table
{
	pid_t			*pid;
	int				philosophers_number;
	int				hungry_size;
	t_timestamp		time_to_eat;
	t_timestamp		time_to_sleep;
	t_timestamp		time_to_die;
	t_timestamp		start_time;
}					t_table;

typedef struct s_philosopher
{
	int				index;
	int				current_action;
	t_timestamp		current_time;
	t_timestamp		last_eating;
	t_timestamp		time_to_eat;
	t_timestamp		time_to_sleep;
	t_timestamp		time_to_die;
	int				hungry_size;
	t_timestamp		start_time;
	sem_t			*prints;
	sem_t			*forks;
	int				finish;
}					t_philosopher;

t_timestamp			ft_get_timestamp(void);
void				ft_mssleep(t_philosopher *philo, int time_in_ms);

int					to_getting_action(t_philosopher *philo);
int					to_sleepy_action(t_philosopher *philo);
int					to_wait_action(t_philosopher *philo);
int					to_eating_action(t_philosopher *philo);
void				to_sleeped_action(t_philosopher *philo);

long				ft_atol(const char *value);
void				*ft_calloc(int size, int weight);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_ttoa(const t_timestamp value);

void				ft_observer_philosopher(t_philosopher *philo);
void				philo_routine(t_table table, t_system sys, int index);
void				finish_table(t_table *table, t_system *sys,
						int exit_status);

#endif