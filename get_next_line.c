/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:02:45 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/10 17:07:37 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 133
#endif

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*aux;
	size_t		count;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	aux = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	count = 0;
	i = 0;
	if (!aux)
		return (NULL);
	while (count < ft_strlen(s1))
	{
		aux[count] = s1[count];
		count++;
	}
	while (i < ft_strlen(s2))
	{
		aux[count] = s2[i];
		count++;
		i++;
	}
	aux[count] = '\0';
	return (aux);
}

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = ft_strlen(str);
	while (count >= 0)
	{
		if (str[count] == (unsigned char)c)
			return ((char *)str + (count));
		count--;
	}
	return (0);
}



int		next_line(char *buff)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buff[i] != '\0' && count == 0)
	{
		if(buff[i] == '\n')
			count = 1;
		i++;
	}
	return (count);
}


char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_static;
	int			count;
	int			prueba;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer_static = malloc(sizeof(char) * BUFFER_SIZE + 1);
	count = 1;
	prueba = 1;
	// printf("%d", count);
	while (count > 0 && !next_line(buffer_static))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
		buffer_static = ft_strjoin(buffer_static,buffer);
		printf("%d ", prueba++);
	}
	return (buffer_static);
}
int main()
{
	printf("%s", get_next_line(open("./hola.txt", O_RDONLY , O_RDONLY)));
	// system("leaks a.out");
}
