/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:17:31 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/20 19:49:40 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	checker(char *argv)
{
	if (ft_memcmp(argv, "here_doc", ft_strlen(argv)) == 0)
		return (1);
	return (0);
}

int	doc_fd(t_values *vals, char *limiter)
{
	char	*line;
	int		temp_fd;

	vals->limiter = limiter;
	temp_fd = open("temp_file", O_CREAT | O_WRONLY, 0666);
	if (temp_fd < 0)
		ft_error2("Error creating temp file\n", 127);
	line = get_next_line(0);
	while(line)
	{
		if ((ft_strlen(line) - 1) == ft_strlen(vals->limiter))
			if (ft_strncmp(line, vals->limiter, ft_strlen(vals->limiter)) == 0)
				break ;
		ft_putstr_fd(line, temp_fd);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(temp_fd);
	return (temp_fd);
}
