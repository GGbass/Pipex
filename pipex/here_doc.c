/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:17:31 by gongarci          #+#    #+#             */
/*   Updated: 2024/05/14 15:47:29 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_here_doc(char *limiter)
{
	char	*line;
	char	*doc;

	line = get_next_line(0);
	doc = ft_strdup("");
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		doc = ft_strjoin(doc, line);
		doc = ft_strjoin(doc, "\n");
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (doc);
}

char **get_doc_array(char *limiter, char *doc)
{
	char	**doc_array;
	int		i;

	i = 0;
	doc_array = ft_split(doc, '\n');
	while (doc_array[i] && ft_strncmp(doc_array[i], limiter, ft_strlen(limiter)))
		i++;
	doc_array[i] = NULL;
	return (doc_array);
}
