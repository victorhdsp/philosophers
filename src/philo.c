/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/27 10:54:07 by vide-sou         ###   ########.fr       */
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

void    *ft_philo_routine(void *arg)
{
    t_philosopher   *philo;
    int             fork;
    int             sleep;

    philo = (t_philosopher *)arg;
    fork = 0;
    sleep = 0;
    printf("%ld %d exist\n", ft_get_current_time(), philo->id);
    ft_set_lifetime(philo, ft_get_current_time());
    while (ft_philo_is_alived(philo) && ft_get_current_time() < ft_get_lifetime(philo) + philo->time_to_die)
    {
        if (sleep)
        {
            ft_usleep(philo->time_to_sleep);
            printf("%ld %d has sleeping\n", ft_get_current_time(), philo->id);
            sleep = 0;
        }
        else if (ft_get_action(philo) == NUL)
        {
            printf("%ld %d has thinking\n", ft_get_current_time(), philo->id);
            ft_set_action(philo, WAIT);
        }
        else if (ft_get_action(philo) == GETTING)
        {
            printf("%ld %d has getted 1 fork\n", ft_get_current_time(), philo->id);
            printf("%ld %d has getted 1 fork\n", ft_get_current_time(), philo->id);
            fork += 2;
            ft_set_action(philo, GETTED);
        }
        else if (ft_get_action(philo) == GETTED)
        {
            ft_usleep(philo->time_to_eat);
            printf("%ld %d has eating\n", ft_get_current_time(), philo->id);
            fork -= 2;
            ft_set_lifetime(philo, ft_get_current_time());
            ft_set_action(philo, RETURNED);
            sleep = 1;
        }
        ft_usleep(10);
    }
    ft_kill_philo(philo);
    return ("ok");
}
