/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:48 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/25 15:25:43 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ft_get_fork(t_system *sys)
{
    int     getting;

    getting = 0;
    pthread_mutex_lock(&sys->mutex);
    if (sys->table.forks >= 2)
    {
        sys->table.forks -= 2;
        getting = 1;
    }
    pthread_mutex_unlock(&sys->mutex);
    return (getting);
}

int    ft_set_id(t_system *sys, int index)
{
    int     getting;

    getting = -1;
    pthread_mutex_lock(&sys->mutex);
    if (sys->cur_id >= 0)
    {
        sys->cur_id = index;
        getting = 1;
    }
    pthread_mutex_unlock(&sys->mutex);
    return (getting);
}

int    ft_kill_philo(t_system *sys, int index)
{
    int     getting;

    getting = -1;
    pthread_mutex_lock(&sys->mutex);
    if (sys->table.philo_list[index].lifetime != -1)
    {
        sys->table.philo_list[index].lifetime = -1;
        getting = 1;
    }
    pthread_mutex_unlock(&sys->mutex);
    return (getting);
}

int    ft_is_alived(t_system *sys, int index)
{
    int     getting;

    getting = 1;
    pthread_mutex_lock(&sys->mutex);
    if (sys->table.philo_list[index].lifetime == -1)
        getting = 0;
    pthread_mutex_unlock(&sys->mutex);
    return (getting);
}

void     ft_monitor(t_system *sys)
{
    int     index;

    index = 0;
    while (index <= 1)
    {
        if (ft_get_current_time() >= sys->table.philo_list[index].lifetime + sys->time_to_die)
            break;
        if (index == 1)
            index = -1;
        index++;
    }
    index = 0;
    while (index < sys->number_of_philo)
    {
        ft_kill_philo(sys, index);
        ft_usleep(10);
        index++;
    }
}