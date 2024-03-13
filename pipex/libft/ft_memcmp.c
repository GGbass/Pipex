/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:07:03 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:52:50 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/

int	ft_memcmp(const void *dest, const void *src, size_t n_bytes)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	s1 = (char *)dest;
	s2 = (char *)src;
	while (i < n_bytes)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char )s2[i]);
		i++;
	}
	return (0);
}
