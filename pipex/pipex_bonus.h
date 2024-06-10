/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:21 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/10 19:07:45 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define READ 0
# define WRITE 1

typedef struct s_values
{
	char	**env;
	char	**cmd;
	char	**doc;
	int		check;
}	t_values;

typedef struct s_pipex
{
	pid_t	pid;
	int		*pipe_fd;
	int		*pre_pipe;
	int		i;
	int		status;
}	t_pipex;

/* Creates a set of fds and forks to pass the output to a new command */
/* int		pipex(int *fd, char **env, char **cmd, int cmd_len); */
int		pipex(int *fd, t_values *vals, int cmd_len);
/*  Find the path of a command in the environment*/
char	*find_path(char *cmd, char **env);

void	ft_error(char *message, int status, t_pipex *pipex);

char	**get_here_doc(char *limiter);

//char **get_doc_array(char *limiter, char *doc);

int		checker(char *argv);

void	ft_cleanup(t_pipex *pipex);

#endif