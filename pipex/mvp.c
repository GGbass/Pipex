/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:03:23 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/02 21:59:44 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* programa 'infile' "comando 1" "comando 2" 'outfile' */
int	main(int argc, char **argv, char **env)
{
	pid_t	parent;
	pid_t	child;
	pid_t	check;
	char	*cmd[2]; // arrays de comandos por terminal
	int		fd[2]; // array de FD 0 entrada , 1 salida , 2 error
	int		pipe_fd[2]; // array de FD para pipe
	int		status;
	int		i;

	check = 0;
	if (argc !=  5)
		return (printf(stderr, "Invalid number of arguments\n"), 0);
	cmd[0] = argv[2]; // primer comando
	cmd[1] = argv[3]; // segundo comando
	fd[0] = open(argv[1], O_RDONLY); // Open the input file
	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644); // Open the output file TRUNCATE can be specified the number permissions like 777 - 0644
	if (fd[0] == -1 || fd[1] == -1)
		return (printf(stderr, "Error opening files\n"), 0);
	pipe(pipe_fd); // Create a pipe receiving file descriptor array // populates fds with two file descriptors
	if (check = fork() == -1) // Create a new process
		return (perror("Error creating child process\n"), -2);
	if (check  == 0) // check de pipe verifica si es el hijo  == 0 o 1 si es el padre
	{
		child = check;
		close(pipe_fd[0]); // Close the read end of the pipe
		dup2(pipe_fd[1], STDOUT_FILENO); // Duplicate the write end of the pipe to stdout  STDOUT_FILENO is a macro for 1 in unistd.h
		close(pipe_fd[1]); // Close the write end of the pipe
		dup2(fd[0], 0); // Duplicate the read end of the pipe to stdin
		close(fd[0]); // Close the read end of the pipe
		cmd[0] = find_path(cmd[0], env); // Find the path of the first command
		execve(cmd[0], &cmd[0], env); // Execute the first command
		if(execve(cmd[0], &cmd[0], env) == -1)
		{
			perror("Error executing command\n");
			exit(128);
		}
	}
	else
	{
		parent = check;
        close(pipe_fd[1]);
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        cmd[1] = find_path(cmd[1], env);
        execve(cmd[1], &cmd[1], env);// Execute the second command
		if(execve(cmd[0], &cmd[0], env) == -1)
		{
			perror("Error executing command\n");
			exit(128);
		}
	}
	close(fd[0]);
	close(fd[1]);
	while (wait(&status) > 0)
		if (WIFEXITED(status))
		{
			i = WEXITSTATUS(status);
			return(i);
		}
	return (0);
}
