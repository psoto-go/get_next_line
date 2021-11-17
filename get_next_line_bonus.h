/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:03:09 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/17 22:55:51 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 132
#endif

char	*get_next_line(int fd);

char	*only_line(char *buffer_static);

int		bool_next_line(char *buff);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *src);

void	*ft_memcpy(void *str1, const void *str2, size_t n);

char	*next_line(char *buffer_static);

#endif