/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/12 23:49:57 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_action(t_philosopher *philo, int value)
{
	pthread_mutex_lock(&philo->mutex);
	philo->action = value;
	pthread_mutex_unlock(&philo->mutex);
}

int	ft_get_action(t_philosopher *philo)
{
	int	getting;

	getting = -1;
	pthread_mutex_lock(&philo->mutex);
	getting = philo->action;
	pthread_mutex_unlock(&philo->mutex);
	return (getting);
}

void	ft_set_current_time(t_philosopher *philo, timestamp value)
{
	pthread_mutex_lock(&philo->mutex);
	philo->current_time = value;
	pthread_mutex_unlock(&philo->mutex);
}

timestamp	ft_get_current_time(t_philosopher *philo)
{
	timestamp	getting;

	getting = -1;
	pthread_mutex_lock(&philo->mutex);
	getting = philo->current_time;
	pthread_mutex_unlock(&philo->mutex);
	return (getting);
}

void	*ft_philo_routine(void *arg)
{
	t_philosopher	*philo;
	int				current_action;

	philo = (t_philosopher *)arg;
	current_action = -1;
	while (current_action != DEAD && current_action != UNHUNGRY)
	{
		current_action = ft_get_action(philo);
		if (current_action == NUL)
			toWaitAction(philo, philo->index, philo->current_time);
		else if (current_action == GETTED)
			toEatingAction(philo, philo->index, philo->current_time);
		else if (current_action == EATING)
			toEatedAction(philo);
		else if (current_action == SLEEPY)
			toSleepedAction(philo);
		else if (current_action == SLEEPED)
			toNulAction(philo);
		ft_set_current_time(philo, ft_get_timestamp());
	}
	return ("ok");
}
