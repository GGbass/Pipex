/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:57:36 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:40:59 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*point;

	b = count * size;
	point = malloc(b);
	if (!point)
		return (NULL);
	else
	{
		ft_bzero(point, b);
	}
	return (point);
}
