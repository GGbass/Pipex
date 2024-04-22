/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:21 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/22 14:01:44 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

/* Creates a set of fds and forks to pass the output to a new command */
int	pipex(int *fd, char **env, char **cmd);

/*  Find the path of a command in the environment*/
char	*find_path(char *cmd, char **env);

/*  */
void	ft_error(char *message, int status);

char	*get_flag(char *cmd);
#endif