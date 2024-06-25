/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:22 by gongarci          #+#    #+#             */
/*   Updated: 2023/11/13 17:42:22 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_unsigned_int(unsigned int number, int *len)
{
	int	aux;

	if (number >= 10)
		ft_unsigned_int(number / 10, len);
	aux = *len;
	if (ft_unprintf(aux, len) == -1)
		return ;
	ft_putchar(number % 10 + '0', len);
}
