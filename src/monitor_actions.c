/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/15 09:43:52 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	to_getting_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_locked_printf(table, current_time, index, "has getted 1 fork");
	ft_locked_printf(table, current_time, index, "has getted 1 fork");
	ft_set_action(philo, GETTED);
	table->forks -= 2;
	return (1);
}

int	to_sleepy_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_locked_printf(table, current_time, index, "has sleeping");
	ft_set_action(philo, SLEEPY);
	table->forks += 2;
	return (1);
}

int	to_wait_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_locked_printf(table, current_time, index, "has thinking");
	ft_set_action(philo, WAIT);
	if (philo->hungry_size == 0)
		ft_set_action(philo, UNHUNGRY);
	return (1);
}

int	to_eating_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_locked_printf(table, current_time, index, "has eating");
	ft_set_action(philo, EATING);
	philo->hungry_size--;
	philo->last_eating = current_time;
	return (1);
}
