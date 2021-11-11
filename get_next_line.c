/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:02:45 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/11 16:44:33 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	count;

	count = 0;
	while (str[count] && str[count] != (unsigned char)c)
		count++;
	if (str[count] == (unsigned char)c)
		return ((char *)str + count);
	return (0);
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
	free((char *)s1);
	return (aux);
}

int		bool_next_line(char *buff)
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

char	*only_line(char *buffer_static)
{
	char	*line;
	int		len;
	int		len2;
	int		count;

	len = ft_strlen(buffer_static);
	len2 = ft_strlen(ft_strchr(buffer_static, '\n'));
	line = malloc(sizeof(char) * len - len2);
	count = 0;
	while ((len - len2) >= count)
	{
		line[count] = buffer_static[count];
		count++;
	}
	free(buffer_static);
	return(line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_static;
	char		*line;
	int			count;
	int			prueba;
	int			i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer_static = malloc(sizeof(char) * BUFFER_SIZE + 1);
	count = 1;
	prueba = 1;
	i = 0;
	// printf("%d", count);
	while (count > 0 && bool_next_line(buffer_static) != 1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
		buffer_static = ft_strjoin(buffer_static,buffer);
		// printf("%d ", prueba++);
	}
	free(buffer);
	line = only_line(buffer_static);
	// buffer_static = NULL;
	buffer_static = ft_strchr(buffer_static, '\n') + 1;
	
	return (line);
}
int main()
{
	int file = open("./hola.txt", O_RDONLY , O_RDONLY);
	printf("%s", get_next_line(file));
	close(file);
	system("leaks a.out");
}
