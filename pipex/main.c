/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/01 18:29:32 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	command1[100];
	char	command2[100];
	char	**pathcheck;

	pathcheck = find_path(argv[1], env);
	//printf("Path: %s\n", pathcheck);
	while (pathcheck[i] != NULL)
	{
		printf("Path: %s\n", pathcheck[i]);
		i++;
	}
	i = 0;
	if (argc != 5)
		return (printf("Wrong number of arguments\n"), 1);
	printf ("Numero de argumentos %d\n", argc);
	printf("infile: '%s'\n command1'%s'\n command2'%s'\n outfile'%s'\n", argv[1], argv[2], argv[3], argv[4]);
/* 	while (env[i] != NULL)
	{
		printf (" Entorno  %s\n", env[i]);
		i++;
	} */
	return (0);
}
