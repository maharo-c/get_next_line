/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:05:23 by margarita         #+#    #+#             */
/*   Updated: 2024/07/01 11:12:57 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}

char	*ft_strncpy(char *src, char *dest, int n_bytes)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n_bytes)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n_bytes)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*pointer;
	unsigned char	*p;
	unsigned int	n;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	p = pointer;
	n = size * count;
	while (n--)
		*p++ = '\0';
	return (pointer);
}
