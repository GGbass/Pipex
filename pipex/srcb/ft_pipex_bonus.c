/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:05 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/26 15:26:40 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	in_to_pipe(t_values *vals, t_pipex *data)
{
	char	**full_command;
	char	*command;

	if (vals->check == 1)
		vals->fd_in = open("temp_file", O_RDONLY);
	if (dup2(vals->fd_in, STDIN_FILENO) < 0)
		ft_error("Error redirecting infile 1\n", 127, data, vals);
	close(vals->fd_in);
	if (dup2(data->pipe_fd[WRITE], STDOUT_FILENO) < 0)
		ft_error("Error redirecting outfile 1\n", 127, data, vals);
	close(data->pipe_fd[WRITE]);
	close(data->pipe_fd[READ]);
	close(vals->fd_out);
	if (!vals->cmd[data->i] || ft_strlen(vals->cmd[data->i]) == 0)
		exit(22);
	if (ft_strncmp(vals->cmd[data->i], "exit", 4) == 0)
		exit(5);
	full_command = ft_split(vals->cmd[data->i], ' ');
	command = find_path(full_command[0], data, vals);
	if (execve(command, full_command, vals->env) == -1)
		ft_error2("Error in child execve\n", 127);
}

static void	pipe_to_pipe(t_values *vals, t_pipex *data)
{
	char	**full_command;
	char	*command;

	close(data->pipe_fd[READ]);
	if (dup2(data->pre_pipe[READ], STDIN_FILENO) < 0)
		ft_error("Error redirecting infile 2\n", 127, data, vals);
	close(data->pre_pipe[READ]);
	if (dup2(data->pipe_fd[WRITE], STDOUT_FILENO) < 0)
		ft_error("Error redirecting outfile 2\n", 127, data, vals);
	close(data->pipe_fd[WRITE]);
	close(data->pipe_fd[READ]);
	close(vals->fd_out);
	close(vals->fd_in);
	close(data->pre_pipe[WRITE]);
	if (!vals->cmd[data->i] || ft_strlen(vals->cmd[data->i]) == 0)
		exit(22);
	if (ft_strncmp(vals->cmd[data->i], "exit", 4) == 0)
		exit(5);
	full_command = ft_split(vals->cmd[data->i], ' ');
	command = find_path(full_command[0], data, vals);
	if (execve(command, full_command, vals->env) == -1)
		ft_error2("Error in child execve\n", 127);
}

static void	pipe_to_out(t_values *vals, t_pipex *data)
{
	char	**full_command;
	char	*command;

	if (dup2(data->pre_pipe[READ], STDIN_FILENO) < 0)
		ft_error("Error redirecting infile 3\n", 127, data, vals);
	close(data->pre_pipe[READ]);
	if (dup2(vals->fd_out, STDOUT_FILENO) < 0)
		ft_error("Error redirecting outfile 3\n", 127, data, vals);
	close(vals->fd_out);
	close(vals->fd_in);
	close(data->pipe_fd[READ]);
	close(data->pipe_fd[WRITE]);
	close(data->pre_pipe[WRITE]);
	if (!vals->cmd[data->i] || ft_strlen(vals->cmd[data->i]) == 0)
		exit(22);
	if (ft_strncmp(vals->cmd[data->i], "exit", 4) == 0)
		exit(5);
	full_command = ft_split(vals->cmd[data->i], ' ');
	command = find_path(full_command[0], data, vals);
	if (execve(command, full_command, vals->env) == -1)
		ft_error2("Error in child execve\n", 127);
}

static void	execute_child(t_pipex *data, int cmd_len, t_values *vals)
{
	if (data->i == 0)
	{
		in_to_pipe(vals, data);
	}
	else if (data->i < cmd_len - 1)
	{
		pipe_to_pipe(vals, data);
	}
	else
		pipe_to_out(vals, data);
}

int	pipex(t_values *vals, int cmd_len)
{
	t_pipex	data;

	data.i = -1;
	data.pipe_fd = ft_calloc(2, sizeof(int ));
	data.pre_pipe = ft_calloc(2, sizeof(int ));
	if (!data.pipe_fd || !data.pre_pipe)
		ft_error("Error allocating memory\n", 126, &data, vals);
	while (vals->cmd && ++data.i < cmd_len)
	{
		if (data.i == 0 || data.i < cmd_len - 1)
			if (pipe(data.pipe_fd) == -1)
				ft_error("Error creating pipe\n", 126, &data, vals);
		data.pid = fork();
		if (data.pid < 0)
			ft_error("Error creating process\n", 125, &data, vals);
		if (data.pid == 0)
			execute_child(&data, cmd_len, vals);
		if (data.i >= 1)
			close(data.pre_pipe[READ]);
		ft_int_memcpy(data.pre_pipe, data.pipe_fd, 2);
		close(data.pipe_fd[WRITE]);
	}
	while (wait(NULL) > 0)
		;
	return (ft_cleanup(&data, vals), 0);
}
