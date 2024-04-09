/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:21 by gongarci          #+#    #+#             */
/*   Updated: 2024/04/07 00:22:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

/* Estructura de datos input & output fds
path  tomado por **env */
typedef struct s_pipex
{
	int				input;
	int				output;
	struct t_list	*next;
	char			**path;
	
} 					t_pipex;


/* Creates a set of fds and forks to pass the output to a new command */
int	pipex(int *fd);

/*  Find the path of a command in the environment*/
char	*find_path(char *cmd, char **env);


void	ft_error(char *message, int status);

#endif