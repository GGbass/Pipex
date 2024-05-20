/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:16:40 by marvin            #+#    #+#             */
/*   Updated: 2024/05/19 22:16:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *message, int status)
{
	perror(message);
	exit(status);
}

// argc 1 program 2 infile - - - - outfile

int	main(int argc, char **argv)
{
	char	**cmd;
	int		fd[2];
	int		pipe_fd[2];
	int		i;

	i = 0;
	if (argc < 5)
		ft_error("Error: Invalid number of arguments\n", 127);
	cmd = malloc(sizeof(char *) * (argc -3));
	while (i < (argc -3))
	{
		cmd[i] = argv[i + 2];
		i++;
	}
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	printf("Hola en la terminal\n");
	
	dup2(fd[1], STDOUT_FILENO);
	write(1, "Hola en el archivo\n", 19);
	i = 0;
	while (cmd[i] != NULL && i < (argc - 3))
	{
		pipe(pipe_fd);
		printf("pipe_fd[0]: %d\n", pipe_fd[0]);
		printf("pipe_fd[1]: %d\n", pipe_fd[1]);
		write(1, cmd[i], ft_strlen(cmd[i]));
		write(1, "\n", 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		i++;
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}