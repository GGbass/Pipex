/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:39:21 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/25 19:11:28 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"



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

