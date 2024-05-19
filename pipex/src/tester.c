/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:01:15 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/18 22:00:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char argv)
{
	int		fd[2];
	int		i;

	i = 0;
	fd[1] = open ("text.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd <= 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	printf ("en la terminal\n");
	if ((dup2(fd[1], STDOUT_FILENO)) == -1)
	{
		printf("Error duplicating file descriptor\n");
		return (1);
	}
	while (i++ < 5 )
		printf ("Hello in the file \n");
	close (fd[1]);
	printf ("En la terminal\n");
	return (0);
}
