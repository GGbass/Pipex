/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:38:54 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/22 15:59:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	command1[100];
	char	command2[100];
	char	*pathcheck;
	char	*flag;
	
	/* flag = get_flag(argv[1]);
	printf("Flag: %s\n", flag);
	pathcheck = find_path(argv[1], env);
	printf("good Path: %s\n", pathcheck);
	pathcheck = find_path(argv[2], env);
	printf("good Path: %s\n", pathcheck);
	while (pathcheck[i])
	{
		printf("Path: %c\n", pathcheck[i]);
		i++;
	} */
	i = 0;
/* 	if (argc != 5)
		return (printf("Wrong number of arguments\n"), 1); */
	printf ("Numero de argumentos %d\n", argc);
/* 	while (argv[i])
		printf("Argumento %d: %s\n", i, argv[i++]); */
	i = 0;
	//printf("infile: '%s'\n command1'%s'\n command2'%s'\n outfile'%s'\n", argv[1], argv[2], argv[3], argv[4]);
	while (env[i] != NULL)
	{
		printf ("Entorno %s\n", env[i]);
		i++;
	}
	return (0);
}
