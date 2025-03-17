/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:22:58 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/17 15:15:37 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atol(const char *value)
{
	int		index;
	long	result;
	int		minus;

	index = 0;
	result = 0;
	minus = 1;
	if (value && value[0] == '-')
	{
		minus = -1;
		index++;
	}
	while (value && value[index])
	{
		if (!(value[index] >= '0' && value[index] <= '9'))
			break ;
		result = (result * 10) + (value[index] - '0');
		index++;
	}
	return (result * minus);
}

void	*ft_calloc(int size, int weight)
{
	char	*result;
	int		index;

	index = 0;
	result = malloc(size * weight);
	if (!result)
		return (NULL);
	while (index < size * weight)
	{
		result[index] = 0;
		index++;
	}
	return ((void *)result);
}
