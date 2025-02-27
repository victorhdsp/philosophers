/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:47:03 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/27 10:16:02 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void          ft_start_table(char **av, t_table *table)
{
    table->forks = ft_atol(av[1]);
    table->philosophers_number = ft_atol(av[1]);
    table->philosophers_list = ft_calloc(ft_atol(av[1]), sizeof(t_philosopher));
    table->start_at = ft_get_current_time();
    table->thread = ft_calloc(ft_atol(av[1]), sizeof(t_table));
}

void     ft_start_philosopher(char **av, int index, t_table *table)
{
    t_philosopher   philo;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    philo.id = index;
    philo.fork_action = 0;
    philo.alived = 1;
    philo.lifetime = -1;
    philo.time_to_die = ft_atol(av[2]);
    philo.time_to_eat = ft_atol(av[3]);
    philo.time_to_sleep = ft_atol(av[4]);
    if (av[5] && av[5][0])
        philo.hungry_size = ft_atol(av[5]);
    else
        philo.hungry_size = -1;
    philo.mutex = mutex;
    table->philosophers_list[index] = philo;
    philo.id = -3;
    pthread_create(&table->thread[index], NULL, ft_philo_routine, &(table->philosophers_list[index]));
}

int     main(int ac, char **av)
{
    int         index;
    t_table     table;

    if (ac > 5 || ac < 4)
        return (-1);
    ft_start_table(av, &table);
    index = 0;
    while (index < table.philosophers_number)
    {
        ft_start_philosopher(av, index, &table);
        ft_usleep(10);
        index++;
    }
    ft_usleep(10);
    ft_monitor_routine(&table);
    index = 0;
    while (index < table.philosophers_number)
    {
        pthread_join(table.thread[index], NULL);
        ft_usleep(10);
        index++;
    }
    free(table.philosophers_list);
    free(table.thread);
}
