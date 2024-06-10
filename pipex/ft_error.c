/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:46:58 by marvin            #+#    #+#             */
/*   Updated: 2024/06/09 20:46:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *message, int status)
{
	perror(message);
	exit(status);
}

void	ft_cleanup(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->i)
	{
		close(pipex->pipe_fd[i]);
		close(pipex->pre_pipe[i]);
		i++;
	}
	free(pipex->pipe_fd);
	free(pipex->pre_pipe);
	exit(pipex->status);
}
