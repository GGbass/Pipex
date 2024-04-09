/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:11:27 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/15 19:07:57 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		ft_gnlstrlen(const char *str);
char	*ft_gnlstrdup(const char *str);
void	*ft_gnlmemcpy(void *dest, const void *src, size_t bytes);
void	*ft_gnlmemset(void *b, int c, size_t len);
int		allocate_memory(char **buffer, char **line);
int		join_and_check(char *buffer, char **line);
int		reader(char **buffer, char **line, int fd);
char	*free_memory(char **p);
char	*ft_gnlstrjoin(char *s1, char *s2, int len2);

#endif