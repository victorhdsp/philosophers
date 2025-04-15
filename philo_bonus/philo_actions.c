/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/04/15 11:20:04 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	to_getting_action(t_philosopher *philo)
{
	t_timestamp	print_time;

	print_time = philo->current_time - philo->start_time;
	sem_wait(philo->prints);
	printf("%lld %d has taken a fork\n", print_time, philo->index);
	printf("%lld %d has taken a fork\n", print_time, philo->index);
	sem_post(philo->prints);
	philo->current_action = GETTED;
	sem_wait(philo->forks);
	return (1);
}

int	to_sleepy_action(t_philosopher *philo)
{
	t_timestamp	print_time;

	print_time = philo->current_time - philo->start_time;
	sem_post(philo->forks);
	sem_wait(philo->prints);
	printf("%lld %d is sleeping\n", print_time, philo->index);
	sem_post(philo->prints);
	philo->current_action = SLEEPY;
	return (1);
}

int	to_wait_action(t_philosopher *philo)
{
	t_timestamp	print_time;

	print_time = philo->current_time - philo->start_time;
	philo->current_action = WAIT;
	ft_mssleep(philo, 3100 / philo->time_to_die);
	if (philo->hungry_size == 0)
		philo->current_action = UNHUNGRY;
	else
	{
		sem_wait(philo->prints);
		printf("%lld %d is thinking\n", print_time, philo->index);
		sem_post(philo->prints);
	}
	return (1);
}

int	to_eating_action(t_philosopher *philo)
{
	t_timestamp	print_time;

	print_time = philo->current_time - philo->start_time;
	philo->hungry_size--;
	sem_wait(philo->prints);
	printf("%lld %d is eating\n", print_time, philo->index);
	sem_post(philo->prints);
	ft_mssleep(philo, philo->time_to_eat);
	philo->last_eating = philo->current_time;
	philo->current_action = EATED;
	return (1);
}

void	to_sleeped_action(t_philosopher *philo)
{
	ft_mssleep(philo, philo->time_to_sleep);
	philo->current_action = SLEEPED;
}
