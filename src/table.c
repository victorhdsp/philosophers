/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:19 by vide-sou          #+#    #+#             */
/*   Updated: 2025/02/19 20:23:19 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ft_get_fork_in_table(t_system *sys)
{
    int     getted;
    t_table *table;

    getted = 0;
    table = &sys->table;
    //pthread_mutex_lock(&table->mutex);
    if (table->fork_numbers >= 2)
    {
        table->fork_numbers -= 2;
        getted = 1;
    }
    //pthread_mutex_unlock(&table->mutex);
    return (getted);
}

int    ft_put_fork_in_table(t_system *sys)
{
    int     getted;
    t_table *table;

    getted = 0;
    table = &sys->table;
    //pthread_mutex_lock(&table->mutex);
    table->fork_numbers += 2;
    getted = 1;
    //pthread_mutex_unlock(&table->mutex);
    return (getted);
}