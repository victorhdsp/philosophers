#include "philo.h"

static void    *ft_start_routine(void *arg)
{
    int     id;
    long     *lifetime;

    id = (*(t_system *)arg).cur_id;
    lifetime = &(*(t_system *)arg).table.philo_list[id];
    *lifetime = ft_get_current_time();
    while (ft_is_alived((t_system *)arg, id))
    {
        ft_get_fork(arg);
        usleep(100);
    }
    
    return ("ok");
}

int     main(void)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    t_system        sys;
    pthread_t       thread_id[2];

    sys.mutex = mutex;
    sys.table.forks = 5;
    sys.table.philo_list[0] = 0;
    sys.table.philo_list[1] = 0;

    ft_get_current_time();
    if (ft_set_id(&sys, 0) && sys.cur_id == 0)
        pthread_create(&thread_id[0], NULL, &ft_start_routine, &sys);
    usleep(1);
    if (ft_set_id(&sys, 1) && sys.cur_id == 1)
        pthread_create(&thread_id[1], NULL, &ft_start_routine, &sys);
    ft_monitor(&sys);
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    printf("numero de garfos: %d, tempo: %ld | %ld\n", sys.table.forks, sys.table.philo_list[0], sys.table.philo_list[1]);
}