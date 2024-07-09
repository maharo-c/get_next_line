/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 06:41:31 by margarita         #+#    #+#             */
/*   Updated: 2024/07/01 23:36:34 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read_text(int fd, char *text);
char	*ft_get_line(char *text);
char	*ft_clean_text(char *text);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join_and_free(char *text, char *buffer);
char	*ft_strncpy(char *src, char *dest, int n_bytes);
void	*ft_calloc(unsigned int count, unsigned int size);
int		ft_strlen(const char *s);

#endif
