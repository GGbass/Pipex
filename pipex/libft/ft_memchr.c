/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:43:20 by gongarci          #+#    #+#             */
/*   Updated: 2023/09/28 10:43:22 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h*/
/*#include <stdio.h>*/

void	*ft_memchr(const void *s, int c, size_t n_bytes)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n_bytes)
	{
		if ((unsigned char)str[i] == (unsigned char )c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/*int   main()
{
    char str[] = "Hola Mundo";
    char *c = ft_memchr(str, 'o', sizeof(str));
    if (c != NULL)
    {
        printf("caracter  'o' encontrado %zu\n", c - str);
    }
    else
    {
        printf(" 'o' No encontrado %zu\n", c);
    }
    return(0);
}*/
