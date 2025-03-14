/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:22:58 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/14 14:18:56 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

static char	*ft_ttoa(const t_timestamp value)
{
	char		*result;
	t_timestamp	tmp;
	int			index;

	index = 0;
	tmp = value;
	if (tmp == 0)
		index = 1;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		index++;
	}
	result = ft_calloc(index + 1, sizeof(char));
	if (!result)
		return (NULL);
	result[index] = '\0';
	tmp = value;
	while (index > 0)
	{
		index--;
		result[index] = '0' + tmp % 10;
		tmp = tmp / 10;
	}
	return (result);
}

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
	while (index < size * weight)
	{
		result[index] = 0;
		index++;
	}
	return ((void *)result);
}

int	ft_locked_printf(t_timestamp current_time, int index, char *msg)
{
	int		size;
	char	*arr[7];
	char	*result;

	arr[0] = ft_ttoa(current_time);
	arr[1] = " ";
	arr[2] = ft_ttoa(index);
	arr[3] = " ";
	arr[4] = msg;
	arr[5] = "\n";
	arr[6] = NULL;
	result = ft_join_multiple(arr);
	size = 0;
	size += write(1, result, ft_strlen(result));
	return (size);
}
