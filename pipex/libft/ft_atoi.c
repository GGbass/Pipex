/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:54:47 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:40:43 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * negative);
}

/*int	main()
{
	char	cadena[] = "  666461855  ";
	char	cadena2[] = "  666 4 61 855";
	int		result;
	int		result2;

	result = ft_atoi(cadena);
	printf("Result of ft_atoi %d\n:", result);
	result2 = atoi(cadena);
	printf("Result of atoi %d\n;", result2);
	return (0);
}*/