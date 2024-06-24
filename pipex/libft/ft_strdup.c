/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:22:11 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/27 11:39:47 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*point;
	size_t	len;

	len = ft_strlen(str);
	point = (char *)malloc(sizeof(*point) * (len + 1));
	if (!point)
		return (NULL);
	ft_memcpy (point, str, len +1);
	return (point);
}

/*int	main(void)
{
	char	*str;

	str = ft_strdup("Hello World");
	printf("valor de str es %s\n", str);
	return (0);
}*/
