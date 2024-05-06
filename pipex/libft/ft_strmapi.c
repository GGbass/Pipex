/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:09:24 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/10 12:21:44 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, 1);
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i] = f(i, *s++);
		i++;
	}
	return (str);
}
/*int	main()
{
	char	str[] = "hello, world";
	char	*new_str;

	printf ("string added : %s\n", str);
	new_str = (ft_strmapi(str, ft_toupper));
	printf("string after strmapi ad using toupper:  %s\n", new_str);
	return (0);
}*/
