/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:03:55 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/25 14:06:43 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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