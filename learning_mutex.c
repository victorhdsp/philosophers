#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_data{
    pthread_mutex_t mutex;
    int             count;
}               t_data;

static void    ft_t_imp_increment(t_data *data, int value)
{
    pthread_mutex_lock(&data->mutex);
    data->count += value;
    pthread_mutex_unlock(&data->mutex);
}

void    *ft_start_routine(void *arg)
{
    int     index;

    index = 0;
    ft_t_imp_increment(arg, 1);
    usleep(100);
    ft_t_imp_increment(arg, 1);
    usleep(100);
    ft_t_imp_increment(arg, 1);
    usleep(100);
    
    return ("ok");
}

int main(void)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    int         num_threads = 30;
    pthread_t   thread_id[num_threads];
    int         index = 0;
    t_data      data;

    (&data)->count = 0;
    (&data)->mutex = mutex;

    while (index < num_threads)
    {
        pthread_create(&thread_id[index], NULL, &ft_start_routine, &data);
        index++;
    }
    index = 0;
    while (index < num_threads)
    {
        pthread_join(thread_id[index], NULL);
        index++;
    }
    printf("count: %d\n", data.count);
    return (0);
}
