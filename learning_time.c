#include <stdio.h>
#include <sys/time.h>

long    ft_get_current_time()
{
    struct timeval  tv;
    long            result;

    gettimeofday(&tv, 0);
    result = (tv.tv_sec * 1000000) + tv.tv_usec;
    return (result);
}

void    ft_usleep(int value)
{
    long    time;

    time = ft_get_current_time() + value;
    while (ft_get_current_time() < time);    
}

void    ft_get_time(int sleep_time, long *current_time)
{
    long diff_time;
    diff_time = ft_get_current_time() - *current_time;
    ft_usleep(sleep_time);
    *current_time = ft_get_current_time() - diff_time;
}

int     main() {
    long started_at;
    long finish_time;
    long current_time;

    current_time = ft_get_current_time();
    finish_time = current_time + 800;
    started_at = current_time;
    while (finish_time > current_time)
    {
        printf("cur time: %ld\n", current_time);
        ft_get_time(500, &current_time);
        finish_time = current_time + 800;
    }
    printf("exited\n");
}