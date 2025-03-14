/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/14 11:17:34 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_kill_philosophers(t_table *table)
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

static int	ft_observer_philosopher(t_table *table, int index,
		t_timestamp current_time, int *finished)
{
	t_philosopher	*philo;
	int				current_action;

	philo = table->philosophers_list[index];
	current_action = ft_get_action(philo);
	if (current_action == UNHUNGRY)
		return (0);
	if (ft_get_current_time(philo) - philo->last_eating > table->time_to_die)
		return (printf("%lld %d has died\n", current_time, index));
	*finished = 0;
	if (current_action == WAIT && table->forks >= 2)
		return (to_getting_action(table, philo, index, current_time));
	if (current_action == EATED)
		return (to_sleepy_action(table, philo, index, current_time));
	return (1);
}

void	ft_monitor_routine(t_table *table)
{
	int			index;
	int			finished;
	t_timestamp	current_time;

	finished = 0;
	while (!finished)
	{
		current_time = ft_get_timestamp();
		index = 0;
		while (index < table->philosophers_number && !finished)
		{
			finished = 1;
			ft_observer_philosopher(table, index, current_time, &finished);
			index++;
		}
	}
	ft_kill_philosophers(table);
}
