/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:07:15 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/01 18:29:18 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char *cmd, char **env)
{
	int	i;
	char	**path;

	i = 0;
	if (cmd[0] == '/' && access(cmd, F_OK) == 0) // If the command is an absolute path
		return (cmd);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			printf("inside 1 if\n");
			//return (env[i]); // linea of the PATH with all directories of commands to match with the command
			path = ft_split(env[i] + 5, ':'); // Split the PATH into an array of directories
			return (path);
		}
		i++;
	}
	return (NULL);
}