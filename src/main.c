/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:47:03 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/25 20:00:38 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void     *ft_start_routine(void *arg)
{
    int     id;
    long    *lifetime;

    id = (*(t_system *)arg).cur_id;
    lifetime = &(*(t_system *)arg).table.philo_list[id].lifetime;
    *lifetime = ft_get_current_time();
    printf("Thread: %d\n", id);
    while (ft_is_alived((t_system *)arg, id))
    {
        printf("Time: %ld\n", *lifetime);
        ft_get_fork(arg);
        ft_usleep(10);
    }
    return ("ok");
}

static void     ft_start_system(t_system *sys, char **av, pthread_mutex_t mutex)
{
    sys->number_of_philo = ft_atol(av[1]);
    sys->time_to_die = ft_atol(av[2]);
    sys->time_to_food = ft_atol(av[3]);
    sys->time_to_sleep = ft_atol(av[4]);
    sys->cur_id = 0;
    sys->mutex = mutex;
    sys->table.forks = ft_atol(av[1]);
    sys->table.philo_list = ft_calloc(ft_atol(av[1]), sizeof(t_philo));
}

int     main(int ac, char **av)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    t_system        sys;
    int             index;
    
    if (ac > 5 || ac < 4)
        return (-1);
    ft_start_system(&sys, av, mutex);
    index = 0;
    while (index < sys.number_of_philo)
    {
        ft_set_id(&sys, index);
        pthread_create(&sys.table.philo_list[index].thread_id, NULL, &ft_start_routine, &sys);
        ft_usleep(10);
        index++;
    }
    ft_monitor(&sys);
    index = 0;
    while (index < sys.number_of_philo)
    {
        pthread_join(sys.table.philo_list[index].thread_id, NULL);
        index++;
    }
    printf("numero de garfos: %d, tempo: %ld | %ld\n", sys.table.forks, sys.table.philo_list[0].lifetime, sys.table.philo_list[1].lifetime);
}

