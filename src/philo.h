/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:17:12 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/14 12:14:32 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define NUL 0
# define WAIT 1
# define GETTED 2
# define EATING 3
# define EATED 4
# define SLEEPY 5
# define SLEEPED 6
# define UNHUNGRY 7
# define DEAD 8

typedef long long	t_timestamp;

typedef struct s_philosopher
{
	pthread_t		thread;
	int				index;
	int				action;
	int				alived;
	t_timestamp		time_to_eat;
	t_timestamp		time_to_sleep;
	t_timestamp		time_to_die;
	int				hungry_size;
	t_timestamp		last_eating;
	t_timestamp		current_time;
	pthread_mutex_t	mutex;
}					t_philosopher;

typedef struct s_table
{
	t_philosopher	**philosophers_list;
	int				philosophers_number;
	t_timestamp		time_to_die;
	int				forks;
}					t_table;

t_timestamp			ft_get_timestamp(void);
void				ft_usleep(int value);

long				ft_atol(const char *value);
void				*ft_calloc(int size, int weight);
int					ft_strlen(char *str);
int					ft_locked_printf(t_timestamp current_time, int index,
						char *msg);

void				ft_monitor_routine(t_table *table);

void				*ft_philo_routine(void *arg);
void				ft_set_action(t_philosopher *philo, int value);
int					ft_get_action(t_philosopher *philo);
void				ft_set_current_time(t_philosopher *philo,
						t_timestamp value);
t_timestamp			ft_get_current_time(t_philosopher *philo);

int					to_wait_action(t_philosopher *philo, int index,
						t_timestamp current_time);
int					to_getting_action(t_table *table, t_philosopher *philo,
						int index, t_timestamp current_time);
int					to_eating_action(t_philosopher *philo, int index,
						t_timestamp current_time);
int					to_sleepy_action(t_table *table, t_philosopher *philo,
						int index, t_timestamp current_time);
int					to_nul_action(t_philosopher *philo);

void				to_eated_action(t_philosopher *philo);
void				to_sleeped_action(t_philosopher *philo);

char				*ft_join_multiple(char **strs);

#endif