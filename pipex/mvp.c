/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:03:23 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/08 21:19:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* programa 'infile' "comando 1" "comando 2" 'outfile' */
int	main(int argc, char **argv, char **env)
{
	pid_t	parent;
	pid_t	child;
	char	*cmd[2]; // arrays de comandos por terminal
	char	*path;
	char	*path1;
	int		fd[2]; // array de FD 0 entrada , 1 salida , 2 error
	int		pipe_fd[2]; // array de FD para pipe
	int		status;
	int		i;

	if (argc !=  5)
		ft_error("Error: Invalid number of arguments\n", 1);
	cmd[0] = argv[2]; // primer comando
	cmd[1] = argv[3]; // segundo comando
	fd[0] = open(argv[1], O_RDONLY); // Open the input file
	fd[1] = open(argv[4], O_CREAT | O_WRONLY);//| O_TRUNC); // Open the output file TRUNCATE can be specified the number permissions like 777 - 0644
	
	/* if (fd[0] == -1 || fd[1] == -1)
		ft_error("Error opening file\n", 2); */

	pipe(pipe_fd); // Create a pipe receiving file descriptor array // populates fds with two file descriptors
	
	child = fork();
	if (child < 0) // Create a new process
		ft_error("Error creating process\n", 1);
	if (child  == 0) // check de pipe verifica si es el hijo  == 0 o 1 si es el padre
	{
		printf("child: %d\n", child);
		dup2(pipe_fd[1], STDOUT_FILENO); // Duplicate the write end of the pipe to stdout  STDOUT_FILENO is a macro for 1 in unistd.h
		printf("after1 dup2\n");
		close(pipe_fd[0]); // Close the read end of the pipe
		//close(pipe_fd[1]); // Close the write end of the pipe
		dup2(fd[0], STDIN_FILENO); // Duplicate the read end of the pipe to stdin
		printf("after 2 dup2\n");
		//cmd = ft_split(cmd[0], ' '); // Split the command into an array of arguments
		printf("cmd[0]: %s\n", cmd[0]);
		path = find_path(cmd[0], env); // Find the path of the first command
		printf("path: %s\n", path);
		if((execve(path, "cat", env)) == -1)
		{
			ft_error("Error executing command\n", 128);
		}
	}
	parent = fork();
	if (parent < 0)
		ft_error("Error creating process\n", 1);
	if (parent == 0)
	{
		printf("parent: %d\n", parent);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		dup2(fd[1], STDOUT_FILENO);
		//cmd = ft_split(cmd[1], ' ');
		printf("cmd[1]: %s\n", cmd[1]);
		path1 = find_path(cmd[1], env);
 		//execve(path, cmd[1], env);// Execute the second command
		printf("path; %s\n", path);
		if((execve(path, "cat", env)) == -1)
		{
			ft_error("Error executing command\n", 127);
		}
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (wait(&status) > 0)
		if (WIFEXITED(status))
		{
			i = WEXITSTATUS(status);
			printf("Exit status: %d\n", i);
			ft_error("Error executing command\n", i);
		}
	return (0);
}
