/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:21 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/07 00:34:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

enum e_errors
{
	NO_ERROR = 0,
	INVALID_NUMBER_OF_ARGUMENTS = -1,
	OPENING_INFILE = -2,
	OPENING_OUTFILE = -3,
	EXECVE_CHILD = -4,
	EXECVE_PARENT = -5,
	NO_FLAG_FOUND = -6,
	ERROR_FINDING_COMMAND = -7
};

/* Creates a set of fds and forks to pass the output to a new command */
int		pipex(int *fd, char **env, char **cmd);
/*  Find the path of a command in the environment*/
char	*find_path(char *cmd, char **env);

void	ft_error(char *message, int status);

#endif