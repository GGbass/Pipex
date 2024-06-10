/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:05 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/10 17:16:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_child(int *fd, int *pipe_fd, char **env, char *cmd)
{
	char	**full_command;
	char	*command;

	if (dup2(fd[READ], STDIN_FILENO) < 0)
		ft_error("Error duplicating file descriptor\n", 127);
	close(fd[0]);
	close(pipe_fd[READ]);
	dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
	close(fd[WRITE]);
	full_command = ft_split(cmd, ' ');
	command = find_path(full_command[0], env);
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}

static void	ft_child2(int *pipe_fd, int *prev_pipe, char **env, char *cmd)
{
	char	**full_command;
	char	*command;

	close(prev_pipe[WRITE]);
	dup2(prev_pipe[READ], STDIN_FILENO);
	close(prev_pipe[READ]);
	dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
	full_command = ft_split(cmd, ' ');
	command = find_path(full_command[0], env);
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}

static void	ft_child3(int *fd, int *pipe_fd, char **env, char *cmd)
{
	char	**full_command;
	char	*command;

	close(pipe_fd[WRITE]);
	dup2(pipe_fd[READ], STDIN_FILENO);
	close(pipe_fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[WRITE]);
	full_command = ft_split(cmd, ' ');
	command = find_path(full_command[0], env);
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}

static void	execute_child(t_pipex *data, int *fd, int cmd_len, t_values *vals)
{
	int	i;

	i = 0;
	if (vals->check == 1 && data->i == 0)
	{
		dup2(data->pipe_fd[WRITE], STDOUT_FILENO);
		close(data->pipe_fd[WRITE]);
		close(data->pipe_fd[READ]);
		while (vals->doc[i] != NULL)
		{
			ft_printf ("%s\n", vals->doc[i]);
			i++;
		}
		exit(0);
	}
	else if (data->i == 0)
		ft_child(fd, data->pipe_fd, vals->env, vals->cmd[data->i]);
	else if (data->i < cmd_len - 1)
		ft_child2(data->pipe_fd, data->pre_pipe, vals->env, vals->cmd[data->i]);
	else
		ft_child3(fd, data->pre_pipe, vals->env, vals->cmd[data->i]);
}

int	pipex(int *fd, t_values *vals, int cmd_len)
{
	t_pipex	data;

	data.i = 0;
	data.pipe_fd = ft_calloc(2, sizeof(int));
	data.pre_pipe = ft_calloc(2, sizeof(int));
	while (vals->cmd[data.i] != NULL && data.i < cmd_len)
	{
		if (data.i == 0 || data.i < cmd_len - 1)
			if (pipe(data.pipe_fd) == -1)
				ft_error("Error creating pipe\n", 126);
		data.pid = fork();
		if (data.pid < 0)
			ft_error("Error creating process\n", 125);
		if (data.pid == 0)
			execute_child(&data, fd, cmd_len, vals);
		if (data.pipe_fd[READ] > 0 && data.pipe_fd[WRITE] > 0)
			ft_int_memcpy(data.pre_pipe, data.pipe_fd, 2);
		close(data.pipe_fd[WRITE]);
		waitpid(data.pid, &data.status, 0);
		data.i++;
	}
	ft_cleanup(&data);
	return (WEXITSTATUS(data.status));
}
