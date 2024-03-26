/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:03:23 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/26 20:40:45 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* programa 'infile' "comando 1" "comando 2" 'outfile' */

int	main(int argc, char **argv, char **env)
{
	pid_t	parent;
	pid_t	child;
	char	*cmd[2]; // arrays de comandos por terminal
	int		fd[2]; // array de FD 0entrada , 1 salida , 2  error

	if (argc !=  5)
		return (printf(stderr, "Invalid number of arguments\n"), 0);
	cmd[0] = argv[2]; // Save the first command
	cmd[1] = argv[3]; // Save the second command
	fd[0] = open(argv[1], O_RDONLY); // Open the input file
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC); // Open the output file TRUNCATE can be specified the number permissions like 777 - 0644
	if (fd[0] == -1 || fd[1] == -1)
		return (printf(stderr, "Error opening file\n"), 0);
	if (pipe(fd) == -1); // Create a pipe
		return (perror("Error creating pipe\n"), -1);
	
	return (0);
}
