#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
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


void	*ft_memcpy(char *dest, const void *src, int n)
{
	char	*cdest;
	char	*csrc;
	char	*fp;
	int	index;

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
	result = ft_calloc(size, sizeof(char));
	if (!result)
		return NULL;
	index = 0;
	while (strs[index])
	{
		ft_memcpy(&result[ft_strlen(result)], strs[index], ft_strlen(strs[index]));
		index++;
	}
	return (result);
}

int	main(void)
{
	char	*srcs[4];
	char	*result;

	srcs[0] = "test";
	srcs[1] = " ";
	srcs[2] = "test";
	srcs[3] = NULL;
	result = ft_join_multiple(srcs);
	write(1, result, ft_strlen(result));
	srcs[0] = "test2";
	srcs[1] = " ";
	srcs[2] = "test2\n";
	srcs[3] = NULL;
	result = ft_join_multiple(srcs);
	write(1, result, ft_strlen(result));
	return(1);
}