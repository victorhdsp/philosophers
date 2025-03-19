/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:22:58 by vide-sou          #+#    #+#             */
/*   Updated: 2025/03/18 14:55:49 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

static void	*ft_memcpy(char *dest, const void *src, int n)
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*result;
	char	*first_point;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	first_point = result;
	if (result)
	{
		if (s1 && *s1)
			ft_memcpy(result, s1, len_s1);
		result += len_s1;
		if (s2 && *s2)
			ft_memcpy(result, s2, len_s2);
	}
	return (first_point);
}
