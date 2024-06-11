/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:01:15 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/30 01:07:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

/* int	main(int argc, char argv)
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
} */

/* int	main(void)
{
	int	y[2];
	int	*x;
	int	i;

	i = 0;
	while (i < 2)
	{
		y[i] = i + 1;
		printf("%d\n", y[i]);
		i++;
	}
	x = y;
	printf("%d\n", x[0]);
	printf("%d\n", x[1]);
	y[1] = 3;
	printf("%d %d\n", y[1], x[1]);
	return (0);
} */
int	main(int argc, char **argv, char **env)
{
	char	**cmd;
	int		fd[2];
	int		status;
	int		i;

	i = 0;
	if (argc < 5)
		ft_error("Error: Invalid number of arguments\n", 127);
	cmd = malloc(sizeof(char *) * (argc -3));
	while (i < (argc -3))
	{
		cmd[i] = argv[i + 2];
		printf("cmd[%d] %s\n", i, cmd[i]);
		i++;
	}
	printf("process in main %d\n",ft_len(cmd));
	status = pipex(fd, env, cmd);
	if (status < 0)
		ft_error("Error in pipex\n", status);
	close(fd[0]);
	close(fd[1]);
	return (status);
}