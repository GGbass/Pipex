/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:34:01 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:58:41 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

/*int	main(void)
{
	char	str[50] = "Esto es una linea de caracteres.";
	printf("\nBefore memset(): %s\n", str);
	ft_memset(str + 5, '.', 15);
	printf("After memset: %s", str);
	return (0);
}*/
