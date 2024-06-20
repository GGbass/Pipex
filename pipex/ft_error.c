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

void	ft_error2(char *message, int status)
{
	ft_putstr_fd(message, 2);
	exit(status);
}

void	ft_error(char *message, int status, t_pipex *data, t_values *vals )
{
	int	i;

	i = 0;
	ft_putstr_fd(message, 2);
	while (i < data->i)
	{
		if (data->pipe_fd[i] > 0)
			close(data->pipe_fd[i]);
		if (data->pre_pipe[i] > 0)
			close(data->pre_pipe[i]);
		i++;
	}
	if (vals->check == 1)
		printf("ft_error\n");
	
	/* while(vals->doc && vals->doc[i] != NULL && vals->check == 10)
	{
		free(vals->doc[i]);
		i++;
	}
	free(vals->doc); */
	free(data->pipe_fd);
	free(data->pre_pipe);
	free(data);
	free(vals);
	exit(status);
}

void ft_fd(t_pipex *data)
{
	printf("data->pipe_fd[0] = %d\n", data->pipe_fd[0]);
	printf("data->pipe_fd[1] = %d\n", data->pipe_fd[1]);
	printf("data->pre_pipe[0] = %d\n", data->pre_pipe[0]);
	printf("data->pre_pipe[1] = %d\n", data->pre_pipe[1]);
}

void	ft_cleanup(t_pipex *data, t_values *vals)
{
	if (vals->check == 1)
		unlink("temp_file");
	free(data->pipe_fd);
	free(data->pre_pipe);
	exit(data->status);
}

/* void ft_doc_clean(char **doc)
{
	int i;

	i = 0;
	while(doc[i] != NULL)
	{
		free(doc[i]);
		i++;
	}
	free(doc);
	return ;
} */