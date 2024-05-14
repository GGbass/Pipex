/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:43:26 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:59:18 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*substr;
	size_t	len;

	len = (ft_strlen(s1) + (ft_strlen(s2)) + 1);
	substr = (char *)malloc(len);
	if (!substr)
		return (NULL);
	else
	{
		ft_memcpy(substr, s1, ft_strlen(s1));
		ft_memcpy(substr + ft_strlen(s1), s2, ft_strlen(s2));
		substr[len - 1] = '\0';
	}
	return (substr);
}

/*int	main()
{
	char	*str1 = "Hola que";
	char	*str2 = "haces";
	char	*sub;

	sub = ft_strjoin(str1, str2);
	printf("la suma de %s\n y %s\n es %s\n", str1, str2, sub);
	free(sub);
	return (0);
}*/