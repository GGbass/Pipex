/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:17:31 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/11 23:10:51 by gongarci         ###   ########.fr       */
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

	line = NULL;
	line = get_next_line(0);
	doc = ft_calloc(1, sizeof(char *) * (sizeof(line)));
	if (!doc || !line)
		ft_error2("Error allocating memory\n", 127);
	*doc = ft_strdup("asd");
	//*doc = ft_strdup(line);
	while (line)
	{
		if ((ft_strlen(line) - 1) == ft_strlen(limiter))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				break ;
		}
		// *doc = ft_strjoin(*doc, "\n");
		*doc = ft_gnlstrjoin(*doc, line, sizeof(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (doc);
}
