/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:40:05 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/15 14:45:59 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	finish_table(t_system *sys)
{
	sem_unlink(sys->sem_forks_name);
	sem_unlink(sys->sem_finish_name);
	exit(EXIT_SUCCESS);
}

static void	start_table(t_table *table, t_system *sys, char **av)
{
	int	index;

	sem_unlink(sys->sem_forks_name);
	sem_unlink(sys->sem_finish_name);
	index = 0;
	table->philosophers_number = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (av[5] && av[5][0])
		table->hungry_size = ft_atol(av[5]);
	else
		table->hungry_size = -1;
	table->pid = ft_calloc(table->philosophers_number, sizeof(pid_t));
	sys->forks = sem_open(sys->sem_forks_name, O_CREAT | O_EXCL, 0644,
			ft_atol(av[1]));
	if (sys->forks == SEM_FAILED)
		finish_table(sys);
	sys->finish = sem_open(sys->sem_finish_name, O_CREAT | O_EXCL, 0644, 0);
	if (sys->finish == SEM_FAILED)
		finish_table(sys);
}

static void	kill_philosophers(t_table table)
{
	int	index;

	index = 0;
	while (index < table.philosophers_number)
	{
		kill(table.pid[index], SIGKILL);
		index++;
	}
}

int	main(int ac, char **av)
{
	t_table		table;
	t_system	sys;
	int			index;

	sys.sem_forks_name = "forks";
	sys.sem_finish_name = "finish";
	if (ac > 6 || ac < 5)
		return (-1);
	start_table(&table, &sys, av);
	index = 0;
	while (index < table.philosophers_number)
	{
		table.pid[index] = fork();
		if (table.pid[index] < 0)
			finish_table(&sys);
		if (table.pid[index] == 0)
			philo_routine(table, sys.forks, sys.finish, index);
		index++;
		ft_usleep(10);
	}
	sem_wait(sys.finish);
	kill_philosophers(table);
	finish_table(&sys);
}
