/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:53:02 by gongarci          #+#    #+#             */
/*   Updated: 2023/11/09 21:53:02 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	ft_hexa(unsigned long long n, int *len)
{
	if (n >= 16)
	{
		ft_hexa(n / 16, len);
		ft_hexa(n % 16, len);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0', len);
		else
			ft_putchar(n - 10 + 'a', len);
	}
}

void	ft_putmem(unsigned long long n, int *len)
{
	int	aux;

	ft_string("0x", len);
	aux = *len;
	if (ft_unprintf(aux, len) == -1)
		return ;
	ft_hexa(n, len);
	aux = *len;
	if (ft_unprintf(aux, len) == -1)
		return ;
}
	//ft_puthexa(n, 'x', len);

/*
	char	*hexa;
	char	str[11];
	int		i;

	i = 0;
	hexa = "0123456789abcdef";
	while (n != 0)
	{
		str[i] = hexa[n % 16];
		n = n / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
*/