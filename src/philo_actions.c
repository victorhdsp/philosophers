/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/15 08:35:56 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
