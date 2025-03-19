/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:40:05 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/19 15:47:36 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_observer_philosopher(t_table table, t_philosopher *philo,
		sem_t *forks)
{
	if (philo->current_action == NUL)
		to_wait_action(philo);
	else if (philo->current_action == WAIT)
		to_getting_action(forks, philo);
	else if (philo->current_action == GETTED)
		to_eating_action(table, philo);
	else if (philo->current_action == EATED)
		to_sleepy_action(forks, philo);
	else if (philo->current_action == SLEEPY)
		to_sleeped_action(table, &philo->current_action);
	else if (philo->current_action == SLEEPED)
		philo->current_action = NUL;
}

void	philo_routine(t_table table, t_system sys, int index)
{
	t_philosopher	philo;

	philo.current_action = NUL;
	philo.current_time = ft_get_timestamp();
	philo.last_eating = philo.current_time;
	philo.hungry_size = table.hungry_size;
	philo.index = index;
	while (philo.current_time - philo.last_eating < table.time_to_die
		&& philo.current_action != UNHUNGRY && table.philosophers_number > 1)
	{
		ft_observer_philosopher(table, &philo, sys.forks);
		usleep(1);
		philo.current_time = ft_get_timestamp();
	}
	if (philo.current_action != UNHUNGRY)
	{
		printf("%lld %d died\n", philo.current_time, philo.index);
		finish_table(&table, &sys, EXIT_SUCCESS);
	}
	finish_table(&table, &sys, EXIT_FAILURE);
}
