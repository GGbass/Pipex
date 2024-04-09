/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:22:33 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:49:44 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(long int n)
{
	int	count;
	int	sign;

	count = 1;
	sign = 0;
	if (n < 0)
	{
		sign += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count + sign);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			size;

	nb = n;
	size = ft_counter(n);
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	while (size - 1 >= 0)
	{
		str[size - 1] = nb % 10 + 48;
		nb /= 10;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*int	main(void)
{
	int		n;
	char	*result;
	char	*result2;

	n = 666461855;
	result = ft_itoa(n);
	printf("Result ft_itoa %s\n:", result);
	result2 = itoa(n);
	printf("Result itoa %s\n:", result2);
	return (0);
}*/

/*int	main(void)
{
	int	n = 
	return (0);
}*/