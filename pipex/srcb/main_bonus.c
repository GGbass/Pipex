/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/26 15:29:55 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	ft_commands(int checker, t_values *vals, int argc, char **argv)
{
	int	i;

	i = 0;
	if (vals->check == 1)
		vals->fd_in = doc_fd(vals, argv[2]);
	if (vals->check == 0)
		vals->fd_in = open(argv[1], O_RDONLY);
	if (vals->fd_in < 0)
		return (ft_error2("Error: no such file or directory\n", 127), -2);
	vals->cmd = ft_calloc(argc - 2 - checker, sizeof(char *));
	if (!vals->cmd)
		ft_error2("Error allocating memory\n", 127);
	while (i < (argc -3 - checker))
	{
		vals->cmd[i] = argv[i + 2 + checker];
		i++;
	}
	vals->cmd[i] = NULL;
	return (i);
}

int	main(int argc, char **argv, char **env)
{
	t_values	vals;
	int			status;
	int			i;

	vals.env = env;
	if (argc < 5 || (checker(argv[1]) == 1 && argc < 6))
		return (ft_error2("Error: Invalid numbers of arguments\n", 127), -1);
	vals.check = checker(argv[1]);
	i = ft_commands(vals.check, &vals, argc, argv);
	if (vals.check == 0)
		vals.fd_out = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (vals.check == 1)
		vals.fd_out = open(argv[argc -1], O_CREAT | O_WRONLY | O_APPEND, 0666);
	status = pipex(&vals, i);
	if (status < 0)
		return (ft_error("Error in pipex\n", status, NULL, NULL), -3);
	free(vals.cmd);
	close(vals.fd_in);
	close(vals.fd_out);
	return (status);
}
