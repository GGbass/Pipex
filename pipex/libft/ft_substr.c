/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:30:52 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/27 11:58:24 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!s)
		return (NULL);
	substr = ft_calloc(len + 1, 1);
	if (!substr)
		return (NULL);
	while (i < len && start < (unsigned int)ft_strlen(s))
	{
		substr[i++] = s[start++];
	}
	return (substr);
}

/*int	main(void)
{
	char	*cadena = "Hola Mundo";
	char	*substr;

	substr = ft_substr(cadena, 5, 6);
	printf("%s\n", substr);
	free(substr);
	return (0);
}*/