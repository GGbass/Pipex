/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:26:47 by gongarci          #+#    #+#             */
/*   Updated: 2023/09/15 12:32:11 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
/*int	main()
{
	if (c == '0')
	{
		return ((char *)s);
	}
	return (NULL);
	const char *string = "Hola Hans";

	int	search = 'a';

	char *result = ft_strrchr(string, search);
	if (result != NULL)
	{
		printf ("'%c' encontrado en  %ld.\n", search, result - string);
	}
	else
	{
		printf("caracter '%c' no fué encontrado en la cadena.\n", search);
	}
	return (0);
}*/