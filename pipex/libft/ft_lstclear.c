/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:35:00 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/17 13:39:10 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*int	main()
{
	t_list	*head;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;
	t_list	*current;

	node = ft_lstnew(ft_strdup("node"));
	head = node;
	node1 = ft_lstnew(ft_strdup("node1"));
	head = node1;
	node2 = ft_lstnew(ft_strdup("node2"));
	head = node2;
	ft_lstclear(&head, del);
	current = head;
	while (!current)
	{
		printf("s\n", current->content);
		current = current->next;
	}
	printf("Final del script.\n");
	return (0);
}*/