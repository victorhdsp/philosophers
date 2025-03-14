/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/14 12:13:52 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	to_getting_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_set_action(philo, GETTED);
	table->forks -= 2;
	ft_locked_printf(current_time, index, "has getted 1 fork");
	ft_locked_printf(current_time, index, "has getted 1 fork");
	return (1);
}

int	to_sleepy_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_set_action(philo, SLEEPY);
	table->forks += 2;
	ft_locked_printf(current_time, index, "has sleeping");
	return (1);
}
