#ifndef PHILO_H
#define PHILO_H

#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_philo {
    pthread_t       thread_id;
    long            lifetime;
}               t_philo;

typedef struct  s_table {
    int             forks;
    t_philo         *philo_list;
}               t_table;

typedef struct  s_system {
    pthread_mutex_t mutex;
    t_table         table;
    int             cur_id;
    int             number_of_philo;
    int             time_to_die;
    int             time_to_food;
    int             time_to_sleep;
}               t_system;

long        ft_get_current_time();
void        ft_usleep(int value);
int         ft_get_fork(t_system *sys);
int         ft_set_id(t_system *sys, int index);
int         ft_kill_philo(t_system *sys, int index);
int         ft_is_alived(t_system *sys, int index);
void        ft_monitor(t_system *sys);
long        ft_atol(const char *value);
char        *ft_itoa(const int value);
void        *ft_calloc(int size, int weight);
int         ft_is_digit(int c);
void        *ft_start_routine(void *arg);

#endif