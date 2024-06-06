/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/06 01:32:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	struct	t_pipex;
	//char	**cmd;
	//char	**doc;
	//int		fd[2];
	int		status;
	int		i;

	i = 0;
	if (argc < 5)
		ft_error("Error: Invalid number of arguments\n", 127);
/*  	if (checker(argv[1]) == 1 && argc >= 6)
	{
		doc = get_here_doc(argv[2]);
	} */
	//cmd = malloc(sizeof(char *) * (argc -3));
	t_pipex.cmd = malloc(sizeof(char *) * (argc -3));
	while (i < (argc -3))
	{
		t_pipex.cmd[i] = argv[i + 2];
		i++;
	}
	t_pipex.fd[0] = open(argv[1], O_RDONLY);
	t_pipex.fd[1] = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	status = pipex(t_pipex.fd, env, t_pipex.cmd, i);
	if (status < 0)
		ft_error("Error in pipex\n", status);
	close(t_pipex.fd[0]);
	close(t_pipex.fd[1]);
	return (status);
}
