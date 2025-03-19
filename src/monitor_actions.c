/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/19 09:48:20 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	to_getting_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	if (index != table->last_philo + 1)
		return (0);
	ft_locked_printf(table, current_time, index, "has getted 1 fork");
	philo->fork[0] = 1;
	ft_locked_printf(table, current_time, index, "has getted 1 fork");
	philo->fork[1] = 1;
	ft_set_action(philo, GETTED);
	table->forks -= 2;
	if (index == table->philosophers_number - 1)
		table->last_philo = -1;
	else
		table->last_philo = index;
	return (1);
}

int	to_sleepy_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_locked_printf(table, current_time, index, "has sleeping");
	ft_set_action(philo, SLEEPY);
	table->forks += 2;
	philo->fork[0] = 0;
	philo->fork[1] = 0;
	return (1);
}

int	to_wait_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_set_action(philo, WAIT);
	if (philo->hungry_size == 0)
		ft_set_action(philo, UNHUNGRY);
	else
		ft_locked_printf(table, current_time, index, "has thinking");
	return (1);
}

int	to_eating_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_locked_printf(table, current_time, index, "has eating");
	ft_set_action(philo, EATING);
	philo->hungry_size--;
	ft_set_last_eating(philo, philo->current_time);
	return (1);
}
