/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/22 17:47:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* programa 'infile' "comando 1" "comando 2" 'outfile' */
int	main(int argc, char **argv, char **env)
{
	char	*cmd[2];
	int		fd[2];
	
	if (argc !=  5)
		ft_error("Error: Invalid number of arguments\n", 1);
	cmd[0] = argv[2];
	cmd[1] = argv[3];
	if ((fd[0] = (open(argv[1], O_RDONLY))) == -1)
		ft_error("Error opening infile\n", 2);
	//fd[0] = open(argv[1], O_RDONLY);
	if ((fd[1] = open(argv[4], O_CREAT | O_WRONLY| O_TRUNC, 0777)) == -1)// TRUNCATE can be specified the number permissions like 777 - 0644
		ft_error("Error opening outfile\n", 3);
	if ((pipex(fd, env, cmd) == -1))
		ft_error("Error in pipex\n", 4);
	return (0);
}
