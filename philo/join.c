/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:22:58 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/14 14:53:59 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memcpy(char *dest, const void *src, int n)
{
	char	*cdest;
	char	*csrc;
	char	*fp;
	int		index;

	cdest = (char *)dest;
	csrc = (char *)src;
	fp = cdest;
	index = 0;
	if (!csrc && !cdest)
		return (NULL);
	while (index < n)
	{
		cdest[index] = csrc[index];
		index++;
	}
	return (fp);
}

char	*ft_join_multiple(char **strs)
{
	int		index;
	int		size;
	char	*result;

	size = 0;
	index = 0;
	while (strs[index])
	{
		size += ft_strlen(strs[index]);
		index++;
	}
	result = ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	index = 0;
	while (strs[index])
	{
		ft_memcpy(&result[ft_strlen(result)], strs[index],
			ft_strlen(strs[index]));
		index++;
	}
	return (result);
}
