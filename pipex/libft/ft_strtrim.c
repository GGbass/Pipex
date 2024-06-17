/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:26:44 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 19:00:29 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while ((j > i) && s1[j -1] && ft_strchr(set, s1[j - 1]))
		j--;
	substr = (char *)malloc(sizeof(char ) * (j - i + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s1[i], j - i + 1);
	return (substr);
}
/*int	main()
{
	char cadena[] = "    estamos en 42   !!";
	char *cadena2 = ft_strtrim(cadena, " ");
	printf("la cadena  es:%s\n Resultado de la funcion %s\n", cadena, cadena2);
	return(0);
}*/
/*Buscamos el primer caracter no espacio,
copiamos la cadena donde inicia sin espacios 
hasta el siguiente espacio*/