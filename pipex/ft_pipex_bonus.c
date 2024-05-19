/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:05 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/18 23:02:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *message, int status)
{
	perror(message);
	exit(status);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*goodpath;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (cmd[0] == '/' && access(cmd, 0) == 0)
		return (cmd);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	cmd = ft_strjoin("/", cmd);
	while (paths[j])
	{
		goodpath = ft_strjoin(paths[j], cmd);
		if (access(goodpath, 0) == 0)
			return (goodpath);
		j++;
	}
	return (ft_error("Error command not found\n", 127),NULL);
}
//static void	ft_child(int *fd, int *pipe_fd, char **env, char **cmd)
static void	ft_child(int input_fd, int output_fd, int *close_fd, char **env, char *cmd)
{
	char **full_command;
	char *command;
	
	/* dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]); */
	if(input_fd >= 0)
		dup2(input_fd, STDIN_FILENO);
	if(output_fd >= 0)
		dup2(output_fd, STDOUT_FILENO);
	/* if (input_fd == -1)
		exit(0); */
	full_command = ft_split(cmd, ' ');
	command = find_path(full_command[0], env);
	printf("in child 1\n");
	close(input_fd);
	close(output_fd);
	close(close_fd[0]);
	close(close_fd[1]);
	printf("in child 2\n");
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}	

//input[0] ------------file----------output[1];
//input[0]-------------pipe----------output[1];
int	pipex(int *fd, char **env, char **cmd)
{
	int		pipe_fd[2];
	int 	*prev_pipe_fd;
	int		status;
	pid_t	child;
	int		i;

	i = 0;
	prev_pipe_fd = NULL;
	if (dup2(fd[0], STDIN_FILENO) < 0)
		ft_error("Error duplicating file descriptor\n", 127);
	while (cmd[i] != NULL)
	{
		printf("before pipe\n");
		if (pipe(pipe_fd) < 0)
			ft_error("Error creating pipe\n", 126);
		child = fork();
		if (child < 0)
			ft_error("Error creating process\n", 125);
		if (child == 0)
		{
			if (i == 0)
				ft_child(fd[0], pipe_fd[1], pipe_fd, env, cmd[i]);
			else if (i < (ft_len(cmd) - 1))
				ft_child(prev_pipe_fd[0], pipe_fd[1], pipe_fd , env, cmd[i]);
			else
				ft_child(prev_pipe_fd[0], fd[1], pipe_fd, env, cmd[i]);
		}
			//ft_child(fd, pipe_fd, env, cmd);
		
		if(prev_pipe_fd != NULL)
		{
			close(prev_pipe_fd[0]);
			close(prev_pipe_fd[1]);
		}
		//waitpid(child, NULL, 0);
		waitpid(child, &status, 0);
		prev_pipe_fd = pipe_fd;
		printf("afterpid\n");
		i++;
	}
	waitpid(child, &status, 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (WEXITSTATUS(status));
}
