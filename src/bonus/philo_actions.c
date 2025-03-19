/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/18 15:19:08 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	to_getting_action(sem_t *forks, t_philosopher *philo)
{
	printf("%lld %d has getted 1 fork\n", philo->current_time, philo->index);
	printf("%lld %d has getted 1 fork\n", philo->current_time, philo->index);
	philo->current_action = GETTED;
	sem_wait(forks);
	sem_wait(forks);
	return (1);
}

int	to_sleepy_action(sem_t *forks, t_philosopher *philo)
{
	printf("%lld %d has sleeping\n", philo->current_time, philo->index);
	philo->current_action = SLEEPY;
	sem_post(forks);
	sem_post(forks);
	return (1);
}

int	to_wait_action(t_philosopher *philo)
{
	philo->current_action = WAIT;
	if (philo->hungry_size == 0)
		philo->current_action = UNHUNGRY;
	else
		printf("%lld %d has thinking\n", philo->current_time, philo->index);
	return (1);
}

int	to_eating_action(t_table table, t_philosopher *philo)
{
	printf("%lld %d has eating\n", philo->current_time, philo->index);
	ft_usleep(table.time_to_eat);
	philo->current_action = EATED;
	philo->hungry_size--;
	philo->last_eating = philo->current_time;
	return (1);
}

void	to_sleeped_action(t_table table, int *current_action)
{
	ft_usleep(table.time_to_sleep);
	*current_action = SLEEPED;
}
