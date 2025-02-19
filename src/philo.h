#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct  s_table {
    pthread_mutex_t mutex;
    int             fork_numbers;
    int             philosophers_count;
}               t_table;

typedef struct  s_system
{
    int             numbers_of_philosophers;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             hunger_size;
    t_table         table;
}               t_system;

int     ft_get_fork_in_table(t_system *sys);
int     ft_put_fork_in_table(t_system *sys);
void    *ft_calloc(int size, int weight);
char    *ft_itoa(const int value);
long    ft_atol(const char *value);
int     ft_is_digit(int c);
void    *ft_start_routine(void *arg);

#endif