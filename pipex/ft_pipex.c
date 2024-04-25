/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:05 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/25 22:31:34 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(int *fd, int *pipe_fd, char **env, char **cmd)
{
	char	*flags;
	char	**full_command;
	char	*command;
	int		status;
	
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	dup2(fd[0], STDIN_FILENO);
	full_command = ft_split(cmd[0], ' ');
	flags = get_flag(cmd[0]);
	command = find_path(full_command[0], env);
	printf("command  in child %s\n", command);
	printf("flags in child %s\n", flags);
	if (execve(command, full_command, NULL) == -1)
	{
		perror("Error in execve in child\n");
		exit(127);
		//ft_error("Error in execve in child\n", 127);
	}
}

static void	ft_parent(int *fd, int *pipe_fd, char **env, char **cmd)
{
	char	*flags;
	char	*command2;
	char	**full_command;
	int		status;

	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	full_command = ft_split(cmd[1], ' ');
	flags = get_flag(cmd[1]);
	command2 = find_path(full_command[0], env);
	if ((execve(command2, full_command, NULL)) == -1)
	{
		perror("Error in execve in child\n");
		exit(127);
		//ft_error("Error in execve in parent\n", 127);
	}
}

int	pipex(int *fd, char **env, char **cmd)
{
	int		pipe_fd[2];
	pid_t	child;
	pid_t	parent;
	int		status;
	
	if ((pipe(pipe_fd)) < 0)
		ft_error("Error creating pipe\n", 124);
	if ((child = fork()) < 0)
		ft_error("Error creating process\n", 123);
	if (child == 0)
		ft_child(fd, pipe_fd, env, cmd);
	if ((parent = fork()) < 0)
		ft_error("Error creating a parent process", 122);
	if (parent == 0)
		ft_parent(fd, pipe_fd, env, cmd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	status = waitpid(child, &status, 0); //wait for standard input on termminal to write it on the pipe outfile
	//waitpid(parent, &status, 0);
	printf("%i\n", status);
	printf("Child %i\n", child);
	printf("Parent %i\n", parent);
	return (status);
}
