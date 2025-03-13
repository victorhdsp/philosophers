/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:47:03 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/13 01:10:27 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_parser(char **av)
{
    if (ft_atol(av[1]) <= 0)
        exit(0);
    if (ft_atol(av[2]) <= 0)
        exit(0);
    if (ft_atol(av[3]) <= 0)
        exit(0);
    if (ft_atol(av[4]) <= 0)
        exit(0);
    if (av[5] && ft_atol(av[5]) <= 0)
        exit(0);
}

static void	ft_start_table(char **av, t_table *table)
{
    table->forks = ft_atol(av[1]);
    table->philosophers_number = ft_atol(av[1]);
    table->time_to_die = ft_atol(av[2]);
    table->philosophers_list = ft_calloc(ft_atol(av[1]), sizeof(t_philosopher *));
}

static void	ft_start_philosopher(char **av, int index, t_table *table)
{
	t_philosopher	*philo;
    
    philo = ft_calloc(1, sizeof(t_philosopher));
    philo->index = index;
    philo->current_time = ft_get_timestamp();
    philo->alived = 1;
    philo->action = NUL;
    philo->time_to_eat = ft_atol(av[3]);
    philo->time_to_sleep = ft_atol(av[4]);
    if (av[5] && av[5][0])
        philo->hungry_size = ft_atol(av[5]);
    else
        philo->hungry_size = -1;
    pthread_mutex_init(&philo->mutex, NULL);
    philo->last_eating = -1;
    pthread_create(&philo->thread, NULL, ft_philo_routine, philo);
    table->philosophers_list[index] = philo;
}

static void ft_end_table(t_table *table)
{
    int             index;
    t_philosopher   *philo;

    index = 0;
    while (index < table->philosophers_number)
    {
        philo = table->philosophers_list[index];
        pthread_detach(philo->thread);
        free(philo);
        index++;
    }
    free(table->philosophers_list);
}

int	main(int ac, char **av)
{
	int		index;
	t_table	table;

	if (ac > 6 || ac < 5)
		return (-1);
    ft_parser(av);
	ft_start_table(av, &table);
	index = 0;
    while (index < table.philosophers_number)
    {
        ft_start_philosopher(av, index, &table);
        ft_usleep(15);
        index++;
    }
    ft_monitor_routine(&table);
    ft_end_table(&table);
}
