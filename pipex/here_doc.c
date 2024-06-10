/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:17:31 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/10 19:49:45 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	checker(char *argv)
{
	if (ft_strncmp(argv, "here_doc", 8) == 0)
		return (1);
	return (0);
}

char	**get_here_doc(char *limiter)
{
	char	*line;
	char	**doc;

	line = get_next_line(0);
	doc = malloc(sizeof(char *) * 1);
	if (!doc)
		ft_error("Error allocating memory\n", 127, NULL);
	*doc = ft_strdup("");
	while (line)
	{
		if ((ft_strlen(line) - 1) == ft_strlen(limiter))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				break ;
		}
		*doc = ft_strjoin(*doc, line);
		*doc = ft_strjoin(*doc, "\n");
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (doc);
}
