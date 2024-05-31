/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:16 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/27 13:59:51 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static size_t	ft_count(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				count++;
		}
		else
			i++;
	}
	return (count + 1);
}

static char	**ft_split_aux(char **pointer, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (k < ft_count(s, c) - 1)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		pointer[k] = ft_substr(s, i, j - i);
		if (!pointer[k])
		{
			ft_free(pointer, k);
			return (NULL);
		}
		k++;
		i = j;
	}
	return (pointer);
}

char	**ft_split(char const *s, char c)
{
	char	**pointer;

	if (!s)
		return (NULL);
	if ((*s == 0 && c == 0) || (!s && c == 0))
	{
		pointer = ft_calloc(1, sizeof(char *));
		return (pointer);
	}
	pointer = ft_calloc(ft_count(s, c), sizeof(char *));
	if (!pointer)
		return (NULL);
	return (ft_split_aux(pointer, s, c));
}
/*
int	main()
{
	char **str;
	int		i;
	char *pala;

	pala  = "";
	str = ft_split(pala, 0);
	i = 0;
	printf("%p\n", str);
	printf("%p\n", str[0]);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	ft_free(str, i - 1);
	return (0);
} */