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

void	ft_error(char *message, int status, t_pipex *pipex)
{
	int	i;

	i = 0;
	perror(message);
	while (i < pipex->i)
	{
		close(pipex->pipe_fd[i]);
		close(pipex->pre_pipe[i]);
		i++;
	}
	free(pipex->pipe_fd);
	free(pipex->pre_pipe);
	exit(status);
}

void ft_fd(t_pipex *pipex)
{
	printf("pipex->pipe_fd[0] = %d\n", pipex->pipe_fd[0]);
	printf("pipex->pipe_fd[1] = %d\n", pipex->pipe_fd[1]);
	printf("pipex->pre_pipe[0] = %d\n", pipex->pre_pipe[0]);
	printf("pipex->pre_pipe[1] = %d\n", pipex->pre_pipe[1]);
}

void	ft_cleanup(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->i)
	{
		//close(pipex->pipe_fd[i]);
		close(pipex->pre_pipe[i]);
		i++;
	}
	free(pipex->pipe_fd);
	free(pipex->pre_pipe);
	exit(pipex->status);
}
