/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/17 23:57:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_commands_check(t_values *vals)
{
	int	i;

	i = 0;
	while (vals->cmd[i] != NULL)
	{
		if (ft_strlen(vals->cmd[i]) <= 1 || !vals->cmd[i])
			if (vals->cmd[i][0] == '/' && access(vals->cmd[i], X_OK) != 0)
			{
				ft_putstr_fd(vals->cmd[i], 2);
				if (vals->check == 1)
					free(vals->doc);
				ft_error2(": Invalid command\n", 127);
			}
		i++;
	}
	return ;
}

static int	ft_commands(int checker, t_values *vals, int argc, char **argv)
{
	int	i;

	i = 0;
	if (checker == 1)
		vals->doc = get_here_doc(argv[2]);
	vals->cmd = ft_calloc(argc - 2 - checker, sizeof(char *));
	if (!vals->cmd)
	{
		free(vals->doc);
		ft_error2("Error allocating memory\n", 127);
	}
	while (i < (argc -3 - checker))
	{
		vals->cmd[i] = argv[i + 2 + checker];
		i++;
	}
	vals->cmd[i] = NULL;
	ft_commands_check(vals);
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
	if (vals.check == 0)
		vals.fd_in = open(argv[1], O_RDONLY);
	if (vals.fd_in < 0)
		return (ft_error2("Error: no such file or directory\n", 127), -2);
	i = ft_commands(vals.check, &vals, argc, argv);
	if (vals.check == 0)
		vals.fd_out = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	vals.fd_out = open(argv[argc -1], O_CREAT | O_WRONLY | O_APPEND, 0666);
	status = pipex(&vals, i);
	if (status < 0)
		return (ft_error("Error in pipex\n", status, NULL, NULL), -3);
	free(vals.cmd);
	close(vals.fd_in);
	close(vals.fd_out);
	return (status);
}
