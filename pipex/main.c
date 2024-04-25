/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/25 22:31:27 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	*cmd[2];
	int		fd[2];

	if (argc !=  5)
		ft_error("Error: Invalid number of arguments\n", 127);
	cmd[0] = argv[2];
	cmd[1] = argv[3];
	if ((fd[0] = (open(argv[1], O_RDONLY))) == -1)
		ft_error("Error: opening infile\n", 126);
	if ((fd[1] = open(argv[4], O_CREAT | O_WRONLY| O_TRUNC, 0644)) == -1)
		ft_error("Error: opening outfile\n", 125);
/* 	if ((pipex(fd, env, cmd) == -1))
		ft_error("Error in pipex\n", 127); */
	return (pipex(fd, env, cmd), 0);
}
