/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/10 19:10:31 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_commands(int checker, t_values *vals, int argc, char **argv)
{
	int	i;

	i = 0;
	if (checker == 1)
		vals->doc = get_here_doc(argv[2]);
	vals->cmd = ft_calloc(sizeof(char *), argc - 3 - checker);
	while (i < (argc -3 - checker))
	{
		vals->cmd[i] = argv[i + 2 + checker];
		i++;
	}
	return (i);
}

int	main(int argc, char **argv, char **env)
{
	t_values	vals;
	int			fd[2];
	int			status;
	int			i;

	vals.env = env;
	if (argc < 5 || (checker(argv[1]) == 1 && argc < 6))
		ft_error("Error: Invalid number of arguments\n", 127, NULL);
	vals.check = checker(argv[1]);
	i = ft_commands(vals.check, &vals, argc, argv);
	if (vals.check == 0)
		fd[0] = open(argv[1], O_RDONLY);
	if (vals.check == 0)
		fd[1] = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	fd[1] = open(argv[argc -1], O_CREAT | O_WRONLY | O_APPEND, 0666);
	status = pipex(fd, &vals, i);
	if (status < 0)
		ft_error("Error in pipex\n", status, NULL);
	close(fd[0]);
	close(fd[1]);
	return (status);
}
