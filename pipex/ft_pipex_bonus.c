/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:05 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/30 01:47:22 by marvin           ###   ########.fr       */
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

static void	ft_child(int *fd, int *pipe_fd, char **env, char *cmd)
{
	char	**full_command;
	char	*command;

	printf("in child command %s\n", cmd);
	printf("pipe_fd[0] in child %d\n", pipe_fd[0]);
	printf("pipe_Fd[1] in child %d\n", pipe_fd[1]);
	close(pipe_fd[0]);
	printf("infile %d\n", fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	printf("Hello from the other side\n");
	close(fd[1]);
	full_command = ft_split(cmd, ' ');
	command = find_path(full_command[0], env);
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}

static void	ft_child2(int *pipe_fd, char **env, char *cmd)
{
	char	**full_command;
	char	*command;
	
	printf("in child2 command %s\n", cmd);
	dup2(pipe_fd[1], STDIN_FILENO);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDOUT_FILENO);
	close(pipe_fd[0]);
	full_command = ft_split(cmd, ' ');
	command = find_path(full_command[0], env);
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}

static void	ft_child3(int *fd, int *pipe_fd, char **env, char *cmd)
{
	char	**full_command;
	char	*command;

	printf("in child3 command %s\n", cmd);
	printf("in child3 pipe_fd[0] %d\n", pipe_fd[0]);
	printf("in child3 pipe_fd[1] %d\n", pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	full_command = ft_split(cmd, ' ');
	command = find_path(full_command[0], env);
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}

int	pipex(int *fd, char **env, char **cmd, int cmd_len)
{
	int		pipe_fd[2];
	int		*prev_pipe;
	int		status;
	pid_t	child;
	int		i;

	i = 0;
	prev_pipe = malloc(sizeof(int) * 2);
	if (!prev_pipe)
		ft_error("Error allocating memory\n", 127);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		ft_error("Error duplicating file descriptor\n", 127);
	close(fd[0]);
	while (cmd[i] != NULL && i < cmd_len)
	{
		if (i == 0 && i < cmd_len - 1)
			if (pipe(pipe_fd) == -1)
				ft_error("Error creating pipe\n", 126);
		/* if ((prev_pipe[0] > 0 || prev_pipe[1] > 0))
		{
			printf("second prev_pipe\n");
			pipe_fd[0] = prev_pipe[1];
			pipe_fd[1] = prev_pipe[0];
		} */
		child = fork();
		if (child < 0)
			ft_error("Error creating process\n", 125);
		if (child == 0)
		{
			if (i == 0)
			{
				close(pipe_fd[0]);
				ft_child(fd, pipe_fd, env, cmd[i]);
			}
			else if (i < cmd_len - 1)
				ft_child2(pipe_fd, env, cmd[i]);
			else
			{
				close(prev_pipe[1]);
				ft_child3(fd, prev_pipe, env, cmd[i]);
			}
		}
		if (pipe_fd[0] > 0 && pipe_fd[1] > 0)
		{
			prev_pipe[0] = pipe_fd[0];
			prev_pipe[1] = pipe_fd[1];
		}
		//close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(child, &status, 0);
		printf("status %d\n", status);
		printf("i: %d\n", i);
		i++;
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free(prev_pipe);
	return (WEXITSTATUS(status));
}
