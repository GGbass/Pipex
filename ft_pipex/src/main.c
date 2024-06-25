/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/25 23:15:52 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**ft_commands(char **argv)
{
	char	*cmd[2];
	cmd[0] = argv[2];
	cmd[1] = argv[3];
	if (ft_len(cmd) == 2)
		if (ft_strlen(cmd[0]) <= 0 || ft_strlen(cmd[1]) <= 0)
			if (access(cmd[0], X_OK) != 0 && access(cmd[1], X_OK) != 0)
				return (-1);
}

int	main(int argc, char **argv, char **env)
{
	char	*cmd[2];
	int		fd[2];
	int		status;

	if (argc != 5)
		return (ft_error("Error: Invalid number of arguments\n", 127), 0);
	cmd[0] = argv[2];
	cmd[1] = argv[3];
	if (ft_len(cmd) == 2)
		if (ft_strlen(cmd[0]) <= 0 || ft_strlen(cmd[1]) <= 0)
			if (access(cmd[0], X_OK) != 0 && access(cmd[1], X_OK) != 0)
				return (-1);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		return (ft_error("No such file or directory\n", 127), 0);
	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	status = pipex(fd, env, cmd);
	if (status < 0)
		ft_error("Error in pipex\n", status);
	close(fd[0]);
	close(fd[1]);
	return (status);
}
