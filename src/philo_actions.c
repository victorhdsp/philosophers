/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/14 12:13:57 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	to_wait_action(t_philosopher *philo, int index, t_timestamp current_time)
{
	ft_set_action(philo, WAIT);
	if (philo->hungry_size == 0)
		ft_set_action(philo, UNHUNGRY);
	ft_locked_printf(current_time, index, "has thinking");
	return (1);
}

int	to_eating_action(t_philosopher *philo, int index, t_timestamp current_time)
{
	ft_set_action(philo, EATING);
	ft_locked_printf(current_time, index, "has eating");
	philo->hungry_size--;
	philo->last_eating = current_time;
	return (1);
}

int	to_nul_action(t_philosopher *philo)
{
	ft_set_action(philo, NUL);
	return (1);
}

void	to_eated_action(t_philosopher *philo)
{
	ft_usleep(philo->time_to_eat);
	ft_set_action(philo, EATED);
}

void	to_sleeped_action(t_philosopher *philo)
{
	ft_usleep(philo->time_to_sleep);
	ft_set_action(philo, SLEEPED);
}
