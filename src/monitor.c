/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/15 09:43:06 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_kill_philosophers(t_table *table, t_timestamp current_time,
		int *finished)
{
	int				index;
	t_philosopher	*philo;

	index = 0;
	while (index < table->philosophers_number)
	{
		*finished = index + 1;
		philo = table->philosophers_list[index];
		if (current_time - philo->last_eating > table->time_to_die)
			return ;
		*finished = 0;
		index++;
	}
}

static int	ft_observer_philosopher(t_table *table, int index,
		t_timestamp current_time)
{
	t_philosopher	*philo;
	int				current_action;

	philo = table->philosophers_list[index];
	current_action = ft_get_action(philo);
	if (current_action == UNHUNGRY)
		return (0);
	if (current_action == NUL)
		return (to_wait_action(table, philo, index, current_time));
	if (current_action == GETTED)
		return (to_eating_action(table, philo, index, current_time));
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
		ft_kill_philosophers(table, current_time, &finished);
		if (finished)
		{
			table->finish = finished;
			break ;
		}
		ft_usleep(10 / table->philosophers_number);
		while (index < table->philosophers_number && !finished)
		{
			ft_observer_philosopher(table, index, current_time);
			index++;
		}
	}
	printf("%lld %i has died\n", current_time, finished - 1);
}
