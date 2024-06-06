/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:14:22 by marvin            #+#    #+#             */
/*   Updated: 2024/06/05 21:14:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *message, int status)
{
	perror(message);
	exit(status);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*goodpath;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (cmd[0] == '/' && access(cmd, 0) == 0)
		return (cmd);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	cmd = ft_strjoin("/", cmd);
	while (paths[j])
	{
		goodpath = ft_strjoin(paths[j], cmd);
		if (access(goodpath, 0) == 0)
			return (goodpath);
		j++;
	}
	return (ft_error("Error command not found\n", 127), NULL);
}
