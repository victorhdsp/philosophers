/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:03:55 by vide-sou          #+#    #+#             */
/*   Updated: 2025/04/15 11:21:04 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_timestamp	ft_get_timestamp(void)
{
	struct timeval	tv;
	t_timestamp		result;

	gettimeofday(&tv, 0);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (result);
}

void	ft_mssleep(t_philosopher *philo, int time_in_ms)
{
	t_timestamp	finish_time;
	t_timestamp	current_time;

	current_time = ft_get_timestamp();
	finish_time = current_time + time_in_ms;
	while (current_time < finish_time)
	{
		if (philo)
			if (current_time - philo->last_eating > philo->time_to_die)
				return ;
		usleep(100);
		current_time = ft_get_timestamp();
	}
}
