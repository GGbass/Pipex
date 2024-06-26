/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:04:42 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/13 14:14:26 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*int	main()
{
	t_list	*head;
	t_list	*list;
	t_list	*list1;
	t_list	*list2;
	int		size;

	while (head != NULL)
	{
		list = ft_lstnew(ft_strdup("list"));
		ft_lstadd_front(&head, list);
		list1 = ft_lstnew(ft_strdup("list1"));
		ft_lstadd_front(&head, list1);
		list2 = ft_lstnew(ft_strdup("list2"));
		ft_lstadd_front(&head, list2);
		size = ft_lstsize(head);
		printf("El tamaño de listas enlazadas es de %d\n:", size);
		free(head);
	}
	return (0);
}
*/