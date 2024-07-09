/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 06:41:09 by margarita         #+#    #+#             */
/*   Updated: 2024/07/03 13:08:23 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*text[FOPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	text[fd] = ft_read_text(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	next_line = ft_get_line(text[fd]);
	text[fd] = ft_clean_text(text[fd]);
	return (next_line);
}

/*int main()
{
    int fd1 = open("empty.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("test3.txt", O_RDONLY);

    char *str1 = get_next_line(fd1);
    char *str2 = get_next_line(fd2);
    char *str3 = get_next_line(fd3);
    while (str1 != NULL)
    {
        printf("%s", str1);
        free(str1);  // Añade esta línea
        str1 = get_next_line(fd1);
    }
    while (str2 != NULL)
    {
        printf("%s", str2);
        free(str2);  // Añade esta línea
        str2 = get_next_line(fd2);
    }
    while (str3 != NULL)
    {
        printf("%s", str3);
        free(str3);  // Añade esta línea
        str3 = get_next_line(fd3);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}*/