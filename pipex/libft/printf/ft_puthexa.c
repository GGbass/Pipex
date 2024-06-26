/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:03:27 by gongarci          #+#    #+#             */
/*   Updated: 2023/11/09 22:03:27 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	ft_recursive(unsigned int number, char c, int *len)
{
	if (number >= 16)
	{
		ft_puthexa(number / 16, c, len);
		ft_puthexa(number % 16, c, len);
	}
}

static	void	ft_minus_or_nine(unsigned int number, int *len)
{
	int	aux;

	if (number <= 9)
	{
		aux = *len;
		if (ft_unprintf(aux, len) == -1)
			return ;
		ft_putchar(number + '0', len);
	}
}

void	ft_puthexa(unsigned int number, char c, int *len)
{
	int	aux;

	if (number >= 16)
		ft_recursive(number, c, len);
	else
	{
		if (number <= 9)
			ft_minus_or_nine(number, len);
		else
		{
			aux = *len;
			if (ft_unprintf(aux, len) == -1)
				return ;
			if (c == 'X')
				ft_putchar((number - 10) + 'A', len);
			else if (c == 'x')
				ft_putchar((number - 10) + 'a', len);
			aux = *len;
			if (ft_unprintf(aux, len) == -1)
				return ;
		}
	}
}
	/*
	char	*hexa;
	char	str[25];
	int		i;
	hexa = "0123456789abcdef";
	i = 0;
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if (number == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (number != 0)
	{
		str[i] = hexa[number % 16];
		number = number / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);*/