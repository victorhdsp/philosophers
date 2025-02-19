/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:19 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/19 20:37:29 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static  int ft_select_action(int *forks, t_system *sys, int id)
{
    if(*forks < 2 && ft_get_fork_in_table(sys))
    {
        *forks += 2;
        printf("%d está pegando 2 garfos\n", id);
        return (0);
    }
    else if (*forks == 2)
    {
        printf("%d está comendo\n", id);
        usleep(sys->time_to_eat);
        if (ft_put_fork_in_table(sys))
            *forks -= 2;
        printf("%d está dormindo\n", id);
        usleep(sys->time_to_sleep);
        return (0);
    }
    else
        printf("%d está pensando\n", id);
    return (1);
}

void    *ft_start_routine(void *arg)
{
    int     forks;
    int     id;
    int     alived;

    forks = 0;
    id = ((t_system *)arg)->table.philosophers_count;
    alived = 1;
    while (alived)
    {
        if (ft_select_action(&forks, (t_system *)arg, id))
            alived = 0;
        if (((t_system *)arg)->table.fork_numbers <= 0)
            break;
    }
    return ("ok");
}
