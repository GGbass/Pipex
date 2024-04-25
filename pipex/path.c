/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:07:15 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/25 21:36:30 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	printf("Error finding command\n");
	return (NULL);
}

char	*get_flag(char *cmd)
{
	char	**lst;
	char	*flag;
	int		i;

	i = 0;
	lst = ft_split(cmd, ' ');
	while (lst[i])
	{
		if (ft_strncmp(lst[i], "-", 1) == 0)
		{
			flag = ft_strdup(lst[i]);
			return (flag);
		}
		i++;
	}
	/* ft_error("Error: No flag found\n", 127); */
	printf("Flag not found\n");
	return (NULL);
}
