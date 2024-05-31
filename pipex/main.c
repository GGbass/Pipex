/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/13 20:10:30 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	*cmd[2];
	int		fd[2];
	int		status;

	if (argc != 5)
		ft_error("Error: Invalid number of arguments\n", 127);
	cmd[0] = argv[2];
	cmd[1] = argv[3];
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	status = pipex(fd, env, cmd);
	if (status < 0)
		ft_error("Error in pipex\n", status);
	close(fd[0]);
	close(fd[1]);
	return (status);
}
