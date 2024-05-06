/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:05 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/07 00:40:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(int *fd, int *pipe_fd, char **env, char **cmd)
{
	char	**full_command;
	char	*command;
	int		status;

	dup2(fd[0], STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (fd[0] == -1)
		exit(0);
	full_command = ft_split(cmd[0], ' ');
	command = find_path(full_command[0], env);
	if (execve(command, full_command, env) == -1)
		ft_error("Error in child execve\n", 127);
}

static void	ft_parent(int *fd, int *pipe_fd, char **env, char **cmd)
{
	char	*command2;
	char	**full_command;
	int		status;

	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (fd[0] > 0 && fd[1] < 0)
		exit(5);
	full_command = ft_split(cmd[1], ' ');
	command2 = find_path(full_command[0], env);
	if (ft_strlen(full_command[0]) == 0 || strcmp(full_command[0], "exit") == 0)
		exit(5);
	if ((execve(command2, full_command, env)) == -1)
		ft_error("Error in parent  execve\n", 5);
}

int	pipex(int *fd, char **env, char **cmd)
{
	int		pipe_fd[2];
	pid_t	child;
	pid_t	parent;
	int		status;

	if ((pipe(pipe_fd)) < 0)
		ft_error("Error creating pipe\n", 124);
	child = fork();
	if (child < 0)
		ft_error("Error creating process\n", 123);
	if (child == 0)
		ft_child(fd, pipe_fd, env, cmd);
	parent = fork();
	if (parent < 0)
		ft_error("Error creating process\n", 123);
	if (parent == 0)
		ft_parent(fd, pipe_fd, env, cmd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child, &status, 0);
	waitpid(parent, &status, 0);
	return (WEXITSTATUS(status));
}
