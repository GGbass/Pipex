/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:02 by gongarci          #+#    #+#             */
/*   Updated: 2023/11/13 17:42:02 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* static	int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
} */

void	ft_string(char *args, int *len)
{
	int	i;

	i = 0;
	if (!args)
	{
		i = write (1, "(null)", 6);
		if (ft_unprintf(i, len) == -1)
			return ;
		*len = *len + 6;
		return ;
	}
	i = write(1, args, ft_strlen(args));
	if (ft_unprintf(i, len) == -1)
		return ;
	*len = *len + ft_strlen(args);
}

	/*while (args[i] != '\0')
		ft_putchar(args[i++], len);
	while (args[i] != '\0')
	{
		if (!isprint(args[i]))
		{
			*len = -1;
			return ;
		}
		i++;
	}
	i = write(1, args, ft_strlen(args));
	*len = *len + ft_strlen(args);
}*/