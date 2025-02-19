/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:59:10 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/19 20:13:48 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static  int ft_start_system(t_system *sys, char **argv, pthread_mutex_t mutex)
{
    sys->numbers_of_philosophers = ft_atol(argv[1]);
    sys->time_to_die = ft_atol(argv[2]);
    sys->time_to_eat = ft_atol(argv[3]);
    sys->time_to_sleep = ft_atol(argv[4]);
    if (argv[5])
        sys->hunger_size = ft_atol(argv[5]);
    (&sys->table)->fork_numbers = ft_atol(argv[1]);
    (&sys->table)->philosophers_count = 0;
    (&sys->table)->mutex = mutex;
    return (1);
}

int main(int ac, char **av)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    t_system        sys;
    pthread_t       thread_id[5];

    (void)ac;
    ft_start_system(&sys, av, mutex);
    pthread_create(&thread_id[0], NULL, &ft_start_routine, &sys);
    (&sys.table)->philosophers_count = 1;
    pthread_create(&thread_id[1], NULL, &ft_start_routine, &sys);
    (&sys.table)->philosophers_count = 2;
    pthread_create(&thread_id[2], NULL, &ft_start_routine, &sys);
    (&sys.table)->philosophers_count = 3;
    pthread_create(&thread_id[3], NULL, &ft_start_routine, &sys);
    (&sys.table)->philosophers_count = 4;
    pthread_create(&thread_id[4], NULL, &ft_start_routine, &sys);
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    pthread_join(thread_id[2], NULL);
    pthread_join(thread_id[3], NULL);
    pthread_join(thread_id[4], NULL);
    printf("%d", sys.table.fork_numbers);
    return (0);
}
