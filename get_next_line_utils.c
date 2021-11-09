/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:03:47 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/09 18:22:33 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

