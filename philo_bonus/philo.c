/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:40:05 by vide-sou          #+#    #+#             */
/*   Updated: 2025/04/14 10:39:33 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_observer_philosopher(t_philosopher *philo)
{
	if (philo->current_action == NUL)
		to_wait_action(philo);
	else if (philo->current_action == WAIT)
		to_getting_action(philo);
	else if (philo->current_action == GETTED)
		to_eating_action(philo);
	else if (philo->current_action == EATED)
		to_sleepy_action(philo);
	else if (philo->current_action == SLEEPY)
		to_sleeped_action(philo);
	else if (philo->current_action == SLEEPED)
		philo->current_action = NUL;
}

void	*ft_philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (philo->current_time - philo->last_eating < philo->time_to_die
		&& philo->current_action != UNHUNGRY)
	{
		philo->current_time = ft_get_timestamp();
		ft_observer_philosopher(philo);
		usleep(1);
	}
	if (philo->current_action != UNHUNGRY)
		philo->current_action = DEAD;
	return ("ok");
}

static void	start_philo(t_philosopher *philo, t_table table, t_system sys,
		int index)
{
	philo->current_action = NUL;
	philo->current_time = ft_get_timestamp();
	philo->last_eating = philo->current_time;
	philo->hungry_size = table.hungry_size;
	philo->index = index;
	philo->start_time = table.start_time;
	philo->prints = sys.prints;
	philo->forks = sys.forks;
	philo->time_to_die = table.time_to_die;
	philo->time_to_eat = table.time_to_eat;
	philo->time_to_sleep = table.time_to_sleep;
}

static void	kill_table(t_table table, t_system sys, int id, int exit_status)
{
	int	index;

	index = 0;
	while (index < table.philosophers_number)
	{
		if (index == id)
			continue ;
		kill(table.pid[index], SIGKILL);
		index++;
	}
	finish_table(&table, &sys, exit_status);
}

void	philo_routine(t_table table, t_system sys, int index)
{
	t_philosopher	philo;
	pthread_t		thread;

	start_philo(&philo, table, sys, index);
	pthread_create(&thread, NULL, ft_philo_routine, &philo);
	pthread_join(thread, NULL);
	if (philo.current_action != UNHUNGRY)
		kill_table(table, sys, index, EXIT_SUCCESS);
	finish_table(&table, &sys, EXIT_FAILURE);
}
