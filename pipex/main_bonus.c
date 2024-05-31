/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/30 01:26:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		i++;
	}
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	status = pipex(fd, env, cmd, i);
	if (status < 0)
		ft_error("Error in pipex\n", status);
	close(fd[0]);
	close(fd[1]);
	return (status);
}
