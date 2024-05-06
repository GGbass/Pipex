/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:11:27 by gongarci          #+#    #+#             */
/*   Updated: 2024/01/09 20:19:50 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t bytes);
void	*ft_memset(void *b, int c, size_t len);
int		allocate_memory(char **buffer, char **line);
int		join_and_check(char *buffer, char **line);
int		reader(char **buffer, char **line, int fd);
char	*free_memory(char **p);
char	*ft_strjoin(char *s1, char *s2, int len2);

#endif