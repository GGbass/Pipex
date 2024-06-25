/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:40:51 by gongarci          #+#    #+#             */
/*   Updated: 2023/11/13 17:40:51 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	ft_max_negative(int number, int *len)
{
	if (number == INT_MIN)
	{
		ft_string("-2147483648", len);
		return ;
	}
}

static	void	ft_recursive(int number, int *len)
{
	if (number >= 10)
	{
		ft_putnbr(number / 10, len);
		ft_putnbr(number % 10, len);
	}
}

void	ft_putnbr(int number, int *len)
{
	char	c_nbr;
	int		aux;

	if (number == INT_MIN)
		ft_max_negative(number, len);
	if (number < 0 && number != INT_MIN)
	{
		number = -number;
		ft_putchar('-', len);
		aux = *len;
		if (ft_unprintf(aux, len) == -1)
			return ;
	}
	if (number >= 10)
		ft_recursive(number, len);
	if (number < 10 && number > -1)
	{
		c_nbr = number + '0';
		aux = *len;
		if (ft_unprintf(aux, len) == -1)
			return ;
		ft_putchar(c_nbr, len);
	}
}
