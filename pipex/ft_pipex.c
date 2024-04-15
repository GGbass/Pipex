/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:05 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/15 21:22:26 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(int *fd, int *pipe_fd, char **env, char **cmd)
{
	char	**p_cmd;
	char	*path;
	int		status;

	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	dup2(fd[0], STDIN_FILENO);
	p_cmd = ft_split(cmd[0], ' ');
	path = find_path(cmd[0], env);
/* 	if ((execve(path, p_cmd, env)) == -1)
		ft_error("error in execve in child \n", 128); */
	if ((execve(path, p_cmd, env)) == -1)
	{
		perror("Error in execve in child\n");
		exit(127);
	}
}

static void	ft_parent(int *fd, int *pipe_fd, char **env, char **cmd)
{
	char	**p_cmd1;
	char	*path1;
	int		status;

	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	p_cmd1 = ft_split(cmd[1], ' ');
	path1 = find_path(cmd[1], env);
	/* if ((execve(path1, p_cmd1, env)) == -1)
		ft_error("error in execve in parent \n", 128); */
	if ((execve(path1, p_cmd1, env)) == -1)
	{
		perror("Error in execve in parent\n");
		exit(127);
	}
}

int	pipex(int *fd, char **env, char **cmd)
{
	int		pipe_fd[2];
	pid_t	child;
	pid_t	parent;
	int		status;
	
	if ((pipe(pipe_fd)) < 0)
		return (perror("Error creating pipe\n"), -1);
		//ft_error("Error creating pipe\n", 1);
	if ((child = fork()) < 0)
		return (perror("Error creating process child\n"), -1);
		//ft_error("Error creating process\n", 2);
	if (child == 0)
		ft_child(fd, pipe_fd, env, cmd);
	if ((parent = fork()) < 0)
		ft_error("Error creating a parent process", 127);
		//perror("Error creating parent process\n");
	if (parent == 0)
		ft_parent(fd, pipe_fd, env, cmd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child, &status, 0); //wait for standard input on termminal to write it on the pipe outfile
	waitpid(parent, &status, 0);
	return (status);
}
