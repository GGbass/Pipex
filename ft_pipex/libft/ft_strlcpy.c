/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:30:32 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:59:58 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*int	main(void)
{
	char		dest[20];
	const char	*name = "Gonzalo";
	const char	*nickname = "Garcia";
	size_t		copy1;
	size_t		copy2;

	copy1 = ft_strlcpy(dest, name, sizeof(dest));
	printf("Copy1: %zu, dest: %s\n", copy1, dest);
	return (0);
}*/
