/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:07:15 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/02 20:12:01 by gongarci         ###   ########.fr       */
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
	perror("ERROR: command not found");
	exit(127);
}