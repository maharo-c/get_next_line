/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:03:47 by margarita         #+#    #+#             */
/*   Updated: 2024/07/03 13:08:22 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

char	*ft_read_text(int fd, char *text)
{
	char	*buffer;
	int		rdbytes;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rdbytes = 1;
	while (rdbytes > 0)
	{
		rdbytes = read(fd, buffer, BUFFER_SIZE);
		if (rdbytes == -1)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		buffer[rdbytes] = '\0';
		text = ft_join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

char	*ft_get_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	str = ft_strncpy(text, str, i + 1);
	str[i + 1] = '\0';
	return (str);
}

char	*ft_clean_text(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free (text);
		return (NULL);
	}
	while (text[j] != '\0')
		j++;
	str = ft_calloc((j - i + 1), sizeof(*text));
	if (!str)
		return (NULL);
	j = 0;
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free (text);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_read_text(fd, text);
	if (!text)
		return (NULL);
	next_line = ft_get_line(text);
	text = ft_clean_text(text);
	return (next_line);
}

/*int main()
{
	int fd = open("empty.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	fd = close(fd);
	return 0;
}*/