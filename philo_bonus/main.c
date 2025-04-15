/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:40:05 by vide-sou          #+#    #+#             */
/*   Updated: 2025/04/14 10:26:17 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_parser(char **av)
{
	if (ft_atol(av[1]) <= 0)
		exit(1);
	if (ft_atol(av[2]) <= 0)
		exit(1);
	if (ft_atol(av[3]) <= 0)
		exit(1);
	if (ft_atol(av[4]) <= 0)
		exit(1);
	if (av[5] && ft_atol(av[5]) <= 0)
		exit(1);
}

void	finish_table(t_table *table, t_system *sys, int exit_status)
{
	sem_unlink(sys->sem_forks_name);
	sem_close(sys->forks);
	sem_unlink(sys->sem_print_name);
	sem_close(sys->prints);
	free(table->pid);
	free(sys->start_timestamp);
	free(sys->sem_forks_name);
	exit(exit_status);
}

static void	start_table(t_table *table, t_system *sys, char **av)
{
	int	index;

	sem_unlink(sys->sem_forks_name);
	sem_unlink(sys->sem_forks_name);
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
	table->start_time = ft_get_timestamp();
	sys->forks = sem_open(sys->sem_forks_name, O_CREAT | O_EXCL, 0644,
			ft_atol(av[1]) / 2);
	sys->prints = sem_open(sys->sem_print_name, O_CREAT | O_EXCL, 0644, 1);
	if (sys->forks == SEM_FAILED)
		finish_table(table, sys, EXIT_FAILURE);
}

static void	kill_philosophers(t_table table, t_system sys)
{
	int	index;
	int	pid_status;
	t_timestamp print_time;

	index = 0;
	while (index < table.philosophers_number)
	{
		waitpid(table.pid[index], &pid_status, 0);
		if (WEXITSTATUS(pid_status) == EXIT_SUCCESS)
		{
			print_time = ft_get_timestamp() - table.start_time;
			sem_wait(sys.prints);
			printf("%lld %d died\n", print_time, index);
		}
		break ;
		index++;
	}
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

	if (ac > 6 || ac < 5)
		return (1);
	sys.start_timestamp = ft_ttoa(ft_get_timestamp());
	sys.sem_forks_name = ft_strjoin("forks_", sys.start_timestamp);
	sys.sem_print_name = ft_strjoin("print_", sys.start_timestamp);
	ft_parser(av);
	start_table(&table, &sys, av);
	index = 0;
	while (index < table.philosophers_number)
	{
		table.pid[index] = fork();
		if (table.pid[index] < 0)
			finish_table(&table, &sys, EXIT_FAILURE);
		if (table.pid[index] == 0)
			philo_routine(table, sys, index);
		index++;
		usleep(1);
	}
	kill_philosophers(table, sys);
	finish_table(&table, &sys, EXIT_SUCCESS);
}
