/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:03:55 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/15 09:12:54 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_timestamp	ft_get_timestamp(void)
{
	struct timeval	tv;
	t_timestamp		result;

	gettimeofday(&tv, 0);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (result);
}

void	ft_usleep(int time_in_ms)
{
	t_timestamp	finish_time;
	t_timestamp	current_time;

	current_time = ft_get_timestamp();
	finish_time = current_time + time_in_ms;
	while (current_time < finish_time)
	{
		usleep(((finish_time - current_time) * 1000) / 2);
		current_time = ft_get_timestamp();
	}
}
