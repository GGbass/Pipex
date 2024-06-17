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

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*goodpath;
	char	*command;
	int		i;

	i = 0;
	command = ft_strdup(cmd);
	if ((cmd[0] == '/' && access(cmd, 0) == 0))
		return (cmd);
	if (ft_strlen(cmd) <= 1 || !cmd)
	{
		ft_putstr_fd(command, 2);
		return (ft_error2(": command not found\n", 127), NULL);
	}
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	cmd = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i])
	{
		goodpath = ft_strjoin(paths[i], cmd);
		if (access(goodpath, 0) == 0)
			return (goodpath);
		i++;
	}
	ft_putstr_fd(command, 2);
	return (ft_error2(": command not found\n", 127), NULL);
}


/* char	*find_path(char *cmd, char **envp)
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
	ft_putstr_fd(cmd, 2);
	ft_error("Error command not found\n", 127, NULL, NULL);
	return (NULL);
} */
