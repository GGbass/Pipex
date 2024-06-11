/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:31:44 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/31 20:52:58 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	ft_check_print(char str, va_list *args, int *len, int *i)
{
	if (str == '%')
		ft_putchar('%', len);
	else if (str == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (str == 's')
		ft_string(va_arg(*args, char *), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (str == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (str == 'x' || str == 'X')
		ft_puthexa(va_arg(*args, unsigned long int), str, len);
	else if (str == 'p')
		ft_putmem(va_arg(*args, unsigned long long), len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_check_print(str[++i], &args, &len, &i);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			ft_putchar((char)str[i++], &len);
			if (len == -1)
				return (-1);
		}
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	int	i;
	int	aux = 0;
	char str[11] = "Hola mundo";
	char caracter = 'a';

	i = 75910;
	printf("%d\n", i / 16);
	printf("%d\n", i % 16);
	printf(" %% %x %d %p\n", i, i, &aux);
	ft_printf("%% %x %d %p\n", i, i, &aux);
	ft_printf("%c\n", caracter + 5);
	return (0);
}*/