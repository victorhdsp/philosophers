/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/12 23:52:48 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_kill_philosophers (t_table *table)
{
	int				index;
	t_philosopher	*philo;

	index = 0;
	while (index < table->philosophers_number)
	{
		philo = table->philosophers_list[index];
		ft_set_action(philo, DEAD);
		index++;
	}
}

static int	ft_observer_philosopher(t_table *table, int index, timestamp current_time, timestamp time_to_die, int *finished)
{
	t_philosopher	*philo;
	int		current_action;

	philo = table->philosophers_list[index];
	current_action = ft_get_action(philo);
	if (current_action == UNHUNGRY)
		return 0;
	if (philo->current_time - philo->last_eating > time_to_die)
		return printf("%lld %d has died\n", current_time, index);
	*finished = 0;
	if (current_action == WAIT && table->forks >= 2)
		return (toGettingAction(table, philo, index, current_time));
	if (current_action == EATED)
		return (toSleepyAction(table, philo, index, current_time));
	return (1);
}

void	ft_monitor_routine(t_table *table)
{
	int				index;
	int				finished;
	timestamp		current_time;

	finished = 0;
	while (!finished)
	{
		current_time = ft_get_timestamp();
		index = 0;
		while (index < table->philosophers_number && !finished)
		{
			finished = 1;
			if (table->philosophers_list[index]->last_eating == -1)
				table->philosophers_list[index]->last_eating = current_time;
			ft_observer_philosopher(table, index, current_time, table->time_to_die, &finished);
			index++;
		}
	}
	ft_kill_philosophers(table);
}
