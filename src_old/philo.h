/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:17:12 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/12 13:58:50 by vide-sou         ###   ########.fr       */
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
# define GETTING 2
# define GETTED 3
# define RETURNED 4

typedef struct s_philosopher
{
	pthread_mutex_t	mutex;
	int				id;
	int				fork_action;
	int				alived;
	long			lifetime;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				hungry_size;
	long			started_at;
}					t_philosopher;

typedef struct s_table
{
	int				forks;
	pthread_t		*thread;
	t_philosopher	*philosophers_list;
	int				philosophers_number;
	long			start_at;
}					t_table;

long				ft_get_current_time(void);
void				ft_usleep(int value);
void				ft_set_lifetime(t_philosopher *philo, long value);
long				ft_get_lifetime(t_philosopher *philo);
void				ft_get_time(int sleep_time, long *current_time);

long				ft_atol(const char *value);
char				*ft_ltoa(const long value);
void				*ft_calloc(int size, int weight);
int					ft_strlen(char *str);

void				ft_monitor_routine(t_table *table);
int					ft_philo_is_alived(t_philosopher *philo);
void				ft_kill_philo(t_philosopher *philo);

void				*ft_philo_routine(void *arg);
void				ft_set_action(t_philosopher *philo, int value);
int					ft_get_action(t_philosopher *philo);

#endif