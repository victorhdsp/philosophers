#ifndef PHILO_H
#define PHILO_H

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_table{
    int             forks;
    long            philo_list[2];
}               t_table;

typedef struct  s_system{
    pthread_mutex_t mutex;
    t_table         table;
    int             cur_id;
}               t_system;

long        ft_get_current_time();
int         ft_get_fork(t_system *sys);
int         ft_set_id(t_system *sys, int index);
int         ft_kill_philo(t_system *sys, int index);
int         ft_is_alived(t_system *sys, int index);
void        ft_monitor(t_system *sys);

#endif