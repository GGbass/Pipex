/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:20:11 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/30 17:48:54 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t bytes_copied)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = bytes_copied;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < bytes_copied)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	str[7] = {"JAMONJA"};
	char	*src = str;
	char	*dest = str + 3;
	printf("dest actual %s\n", dest);
	ft_memmove(dest, src, 5);
	printf("%s\n", dest);
	return (0);
}*/
