/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/10 12:28:48 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_set_action(t_philosopher *philo, int value)
{
    pthread_mutex_lock(&philo->mutex);
    philo->fork_action = value;
    pthread_mutex_unlock(&philo->mutex);
}

int     ft_get_action(t_philosopher *philo)
{
    int     getting;

    getting = 0;
    pthread_mutex_lock(&philo->mutex);
    getting = philo->fork_action;
    pthread_mutex_unlock(&philo->mutex);
    return (getting);
}

int     ft_get_id(t_philosopher *philo)
{
    int     getting;

    getting = 0;
    pthread_mutex_lock(&philo->mutex);
    getting = philo->id;
    pthread_mutex_unlock(&philo->mutex);
    return (getting);
}

void    *ft_philo_routine(void *arg)
{
    t_philosopher   *philo;
    int             fork;
    int             sleep;
    long            current_time;

    philo = (t_philosopher *)arg;
    fork = 0;
    sleep = 0;
    current_time = ft_get_current_time();
    ft_set_lifetime(philo, current_time - philo->started_at);
    while (ft_philo_is_alived(philo) && current_time - philo->started_at < ft_get_lifetime(philo) + philo->time_to_die)
    {
        if (sleep)
        {
            ft_get_time(philo->time_to_sleep, &current_time);
            printf("%ld %d has sleeping\n", current_time - philo->started_at, ft_get_id(philo));
            sleep = 0;
        }
        else if (ft_get_action(philo) == NUL)
        {
            printf("%ld %d has thinking\n", current_time - philo->started_at, ft_get_id(philo));
            ft_set_action(philo, WAIT);
        }
        else if (ft_get_action(philo) == GETTING)
        {
            printf("%ld %d has getted 1 fork\n", current_time - philo->started_at, ft_get_id(philo));
            printf("%ld %d has getted 1 fork\n", current_time - philo->started_at, ft_get_id(philo));
            fork += 2;
            ft_set_action(philo, GETTED);
        }
        else if (ft_get_action(philo) == GETTED)
        {
            ft_get_time(philo->time_to_eat, &current_time);
            printf("%ld %d has eating\n", current_time - philo->started_at, ft_get_id(philo));
            fork -= 2;
            ft_set_lifetime(philo, current_time - philo->started_at);
            ft_set_action(philo, RETURNED);
            sleep = 1;
        }
        ft_get_time(1, &current_time);
    }
    ft_kill_philo(philo);
    return ("ok");
}
