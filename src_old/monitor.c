/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/10 14:03:27 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_kill_philo(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->alived = 0;
	pthread_mutex_unlock(&philo->mutex);
}

int	ft_philo_is_alived(t_philosopher *philo)
{
	int	getting;

	getting = 0;
	pthread_mutex_lock(&philo->mutex);
	getting = philo->alived;
	pthread_mutex_unlock(&philo->mutex);
	return (getting);
}

void	ft_kill_all_philos(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->philosophers_number)
	{
		ft_kill_philo(&table->philosophers_list[index]);
		index++;
	}
}

void	ft_monitor_routine(t_table *table)
{
	int		index;
	long	current_time;
	int		finish;

	current_time = ft_get_current_time();
	while (1)
	{
		index = 0;
		finish = 0;
		while (index < table->philosophers_number)
		{
			if ((&table->philosophers_list[index])->hungry_size == 0)
				finish++;
			if (!ft_philo_is_alived(&table->philosophers_list[index]))
			{
				ft_kill_all_philos(table);
				printf("%ld %d has died\n", current_time - table->start_at,
					index);
				return ;
			}
			if (ft_get_action(&table->philosophers_list[index]) == WAIT
				&& table->forks >= 2)
			{
				table->forks -= 2;
				ft_set_action(&table->philosophers_list[index], GETTING);
			}
			if (ft_get_action(&table->philosophers_list[index]) == RETURNED)
			{
				table->forks += 2;
				ft_set_action(&table->philosophers_list[index], NUL);
			}
			index++;
		}
		if (finish == table->philosophers_number)
			return ;
		ft_get_time(1, &current_time);
	}
}
