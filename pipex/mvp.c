/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:03:23 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/01 18:40:19 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* programa 'infile' "comando 1" "comando 2" 'outfile' */

int	main(int argc, char **argv, char **env)
{
	pid_t	parent;
	pid_t	child;
	char	*cmd[2]; // arrays de comandos por terminal
	int		fd[2]; // array de FD 0entrada , 1 salida , 2  error
	int		check;

	check = 0;
	if (argc !=  5)
		return (printf(stderr, "Invalid number of arguments\n"), 0);
	cmd[0] = argv[2]; // Save the first command
	cmd[1] = argv[3]; // Save the second command
	fd[0] = open(argv[1], O_RDONLY); // Open the input file
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC); // Open the output file TRUNCATE can be specified the number permissions like 777 - 0644
	if (fd[0] == -1 || fd[1] == -1)
		return (printf(stderr, "Error opening file\n"), 0);
	if (check = pipe(fd) == -1); // Create a pipe receiving file descriptor array // populates fds with two file descriptors
		return (perror("Error creating pipe\n"), -1);
	if (check  == 0) // check de pipe verifica si es el hijo  == 0 o 1 si es el padre
	{
		close(fd[0]); // Close the read end of the pipe
		dup2(fd[1], STDOUT_FILENO); // Duplicate the write end of the pipe to stdout  STDOUT_FILENO is a macro for 1 in unistd.h
		close(fd[1]); // Close the write end of the pipe
		execve(cmd[0], &cmd[0], env); // Execute the first command
	}
	else
	{
		close(fd[1]); // Close the write end of the pipe
		dup2(fd[0], 0); // Duplicate the read end of the pipe to stdin
		close(fd[0]); // Close the read end of the pipe
		execve(cmd[1], &cmd[1], env); // Execute the second command
	}
	fork (); // Create a new process
	return (0);
}
