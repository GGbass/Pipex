/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:01:15 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/14 20:05:43 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char argv)
{
	int		fd;
	fd = open("text.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd <= 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	printf("en la terminal\n");
	if ((dup2(fd, STDOUT_FILENO)) == -1)
	{
		printf("Error duplicating file descriptor\n");
		return (1);
	}
	printf("En el archivo\n");
	printf("En el archivo\n");
	printf("En el archivo\n");
	printf("En el archivo\n");

	close(fd);
	printf("En la terminal\n");
	return (0);
}