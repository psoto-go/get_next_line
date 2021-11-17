/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:02:45 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/17 17:14:34 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		bool_next_line(char *buff)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!buff)
		return (count);
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
	int		i;

	len = 0;
	i = 0;
	while (buffer_static[len] && buffer_static[len] != '\n')
	{
		len++;
	}
	if (buffer_static[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return(NULL);
	len = 0;
	while (buffer_static[len] && buffer_static[len] != '\n')
	{
		line[len] = buffer_static[len];
		len++;
	}
	if (buffer_static[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return(line);
}

char	*next_line(char *buffer_static)
{
	int 	count;
	int		len;
	char	*buffer2;
	int		i;

	count = 0;
	len = ft_strlen(buffer_static);
	i = 0;
	while(buffer_static[count] && buffer_static[count] != '\n')
		count++;
	if (buffer_static[count] == '\n')
		count++;
	buffer2 = malloc(sizeof(char) * (len + 1));
	if (!buffer2)
		return(NULL);
	while(buffer_static[count])
	{
		buffer2[i] = buffer_static[count];
		i++;
		count++;
	}
	buffer2[i] = '\0';
	free(buffer_static);
	return (buffer2);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_static;
	char		*line;
	int			count;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	if (!buffer_static)
		buffer_static = ft_strdup("");
	count = 1;
	while (count > 0 && bool_next_line(buffer_static) != 1 )
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buffer[count] = '\0';
		buffer_static = ft_strjoin(buffer_static, buffer);
	}
	free(buffer);
	if (!*buffer_static)
		return(NULL);
	line = only_line(buffer_static);	
	buffer_static = next_line(buffer_static);
	return (line);
}

void	leaks()
{
	system("leaks a.out");
}
int main()
{
	int file = open("./gnlTester/files/big_line_with_nl", O_RDWR);
	char *line = get_next_line(file);
	int count;

	count = 0;
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(file);
		count++;
	}
	free(line);
	// printf("%s", line);
	// free(line);
	// line = get_next_line(file);
	// free(line);
	// system("leaks a.out");
	// system("");
	atexit(leaks);
}
