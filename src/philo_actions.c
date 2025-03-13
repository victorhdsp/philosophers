/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/12 23:53:01 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	toGettingAction (t_table *table, t_philosopher *philo, int index, timestamp current_time)
{
	ft_set_action(philo, GETTED);
	table->forks -= 2;
	printf("%lld %d has getted 1 fork\n", current_time, index);
	return printf("%lld %d has getted 1 fork\n", current_time, index);
}

int	toSleepyAction (t_table *table, t_philosopher *philo, int index, timestamp current_time)
{
	ft_set_action(philo, SLEEPY);
	table->forks += 2;
	return printf("%lld %d has sleeping\n", current_time, index);
}

int	toWaitAction (t_philosopher *philo, int index, timestamp current_time)
{
	ft_set_action(philo, WAIT);
	if (philo->hungry_size == 0)
		ft_set_action(philo, UNHUNGRY);
	return printf("%lld %d has thinking\n", current_time, index);
}

int	toEatingAction (t_philosopher *philo, int index, timestamp current_time)
{
	ft_set_action(philo, EATING);
	printf("%lld %d has eating\n", current_time, index);
	philo->hungry_size--;
	philo->last_eating = current_time;
	return 1;
}

int	toNulAction (t_philosopher *philo)
{
	ft_set_action(philo, NUL);
	return 1;
}

void	toEatedAction (t_philosopher *philo)
{
	ft_usleep(philo->time_to_eat);
	ft_set_action(philo, EATED);
}

void	toSleepedAction (t_philosopher *philo)
{
	ft_usleep(philo->time_to_sleep);
	ft_set_action(philo, SLEEPED);
}