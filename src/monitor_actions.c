/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/14 11:14:15 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	to_getting_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_set_action(philo, GETTED);
	table->forks -= 2;
	printf("%lld %d has getted 1 fork\n", current_time, index);
	return (printf("%lld %d has getted 1 fork\n", current_time, index));
}

int	to_sleepy_action(t_table *table, t_philosopher *philo, int index,
		t_timestamp current_time)
{
	ft_set_action(philo, SLEEPY);
	table->forks += 2;
	return (printf("%lld %d has sleeping\n", current_time, index));
}
