/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:20:43 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/26 20:48:10 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int *fd)
{
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	command1[100];
	char	command2[100];
	i = 0;
	if (argc != 5)
		return (printf("Wrong number of arguments\n"), 1);
	printf ("Numero de argumentos %d\n", argc);
	printf("infile: '%s'\n command1'%s'\n command2'%s'\n outfile'%s'\n", argv[1], argv[2], argv[3], argv[4]);
	while (env[i] != NULL)
	{
		printf (" Entorno  %s\n", env[i]);
		i++;
	}
	return (0);
}
/* programa 'infile' "comando 1" "comando 2" 'outfile' */

/* 	int	i;
	
	i = 0;
	printf ("Numero de argumentos %d\n", argc);
	while (i < argc)
	{
		printf ("argumento %d: %s\n", i, argv[i]);
		i++;
	}
	i = 0;
	while (env[i] != NULL)
	{
		printf (" Entorno  %s\n", env[i]);
		i++;
	} */