/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:03:55 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/27 09:56:09 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_set_lifetime(t_philosopher *philo, long value)
{
    pthread_mutex_lock(&philo->mutex);
    philo->lifetime = value;
    pthread_mutex_unlock(&philo->mutex);
}

long    ft_get_lifetime(t_philosopher *philo)
{
    long     getting;

    getting = 0;
    pthread_mutex_lock(&philo->mutex);
    getting = philo->lifetime;
    pthread_mutex_unlock(&philo->mutex);
    return (getting);
}

long    ft_get_current_time()
{
    struct timeval  tv;
    long            result;

    gettimeofday(&tv, 0);
    result = (tv.tv_sec * 1000000) + tv.tv_usec;
    return (result);
}

void    ft_usleep(int value)
{
    long    time;

    time = ft_get_current_time() + value;
    while (ft_get_current_time() < time);    
}