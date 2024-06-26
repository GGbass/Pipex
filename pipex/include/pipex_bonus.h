/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:21 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/26 15:44:43 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>

# define READ 0
# define WRITE 1

typedef struct s_values
{
	char	**env;
	char	**cmd;
	char	*limiter;
	int		check;
	int		fd_in;
	int		fd_out;
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
int		pipex(t_values *vals, int cmd_len);
/*  Find the path of a command in the environment*/
char	*find_path(char *cmd, t_pipex *data, t_values *vals);

void	ft_error(char *message, int status, t_pipex *data, t_values *vals);
/* When an error happen but just exit is needed */
void	ft_error2(char *message, int status);
/* If we have here_doc as second argv == 1 */
int		checker(char *argv);
/* freeing mem in pipes and unlink*/
void	ft_cleanup(t_pipex *data, t_values *vals);
/* printing pipes and pre-pipes */
void	ft_fd(t_pipex *pipex);
/* getting everythig from stdin and saving in a temp file */
int		doc_fd(t_values *vals, char *limiter);

#endif