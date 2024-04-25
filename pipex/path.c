/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:07:15 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/22 17:32:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* char	**find_path(char *cmd, char **env)
{
	int	i;
	char	**path_list;
	char	*path;

	i = 0;
	if (cmd[0] == '/' && access(cmd, F_OK) == 0) // If the command is an absolute path
		return (cmd);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			printf("inside 1 if\n");
			//return (env[i]); // linea of the PATH with all directories of commands to match with the command
			path_list = ft_split(env[i] + 5, ':'); // Split the PATH into an array of directories
			return (path_list);
		}
		i++;
	}
	return (NULL);
} */
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
	
	ft_error("ERROR: Finding command", 127);
	/* perror("Error in find_path\n");
	exit(127); */
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
	return (NULL);
}
