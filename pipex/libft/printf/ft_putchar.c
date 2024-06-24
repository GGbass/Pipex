/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:08:30 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/31 20:49:30 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar(char c, int *len)
{
	int	aux;

	aux = write (1, &c, 1);
	if (ft_unprintf(aux, len) == -1)
		return ;
	(*len)++;
}
