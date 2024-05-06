/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:06:43 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/20 12:24:53 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/
/*#include <stdio.h>*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p_dest;
	char	*p_src;
	size_t	i;

	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	p_dest = (char *)dest;
	p_src = (char *)src;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

/* if (dest != NULL && src != NULL && n > 0) {
  ft_memcpy(dest, src, n);
} else {
  // Desbordamiento de buffer script.
}*/
/*int	main()
{
	char	dest[7];
	char	src[] = "Hola Mundo!";
	size_t	len;

	len = sizeof(src);
	printf ("%zu\n", len);
	ft_memcpy(dest, src, sizeof(src));
	printf("Resultado de dest es %s\n :", dest);
	return (0);
}*/
