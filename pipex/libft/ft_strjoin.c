/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:43:26 by gongarci          #+#    #+#             */
/*   Updated: 2024/06/20 21:26:09 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*substr;
	size_t	len;

	len = (ft_strlen(s1) + (ft_strlen(s2)) + 1);
	substr = (char *)ft_calloc(len, sizeof(char));
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
