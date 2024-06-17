/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:17:31 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/17 23:45:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	checker(char *argv)
{
	if (ft_memcmp(argv, "here_doc", ft_strlen(argv)) == 0)
		return (1);
	return (0);
}

char	**get_here_doc(char *limiter)
{
	char	*line;
	char	**doc;

	line = get_next_line(0);
	doc = ft_calloc(1, sizeof(char *) * (ft_strlen(line) + 1));
	if (!doc || !line)
	{
		free(line);
		ft_error2("Error allocating memory\n", 127);
	}
	*doc = ft_strdup("");
	while (line)
	{
		if ((ft_strlen(line) - 1) == ft_strlen(limiter))
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				break ;
		*doc = ft_gnlstrjoin(*doc, line, sizeof(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	doc[ft_len(doc)] = NULL;
	return (doc);
}

void	doc_child(t_pipex *data, t_values *vals)
{
	int i;

	i = 0;
	{
		close(data->pipe_fd[READ]);
		dup2(data->pipe_fd[WRITE], STDOUT_FILENO);
		close(data->pipe_fd[WRITE]);
		close(vals->fd_out);
		while (vals->doc[i] != NULL)
		{
			ft_printf ("%s", vals->doc[i]);
			i++;
		}
		while (vals->doc && i >= 0)
			free(vals->doc[i--]);
		free(vals->doc);
		exit(0);
	}
}
