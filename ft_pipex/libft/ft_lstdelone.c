/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:09:17 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/17 15:14:11 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*int	main()
{
	t_list	*head;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = ft_lstnew(ft_strdup("node"));
	node1 = ft_lstnew(ft_strdup("node1"));
	node2 = ft_lstnew(ft_strdup("node2"));
	ft_lstadd_front(&head, node);
	printf("%s\n", head->content);
	ft_lstadd_front(&head, node1);
	printf("%s\n", head->content);
	ft_lstadd_front(&head, node2);
	printf("%s\n", head->content);
	ft_lstdelone(node, free);
	head = node2;
	while (head->content != NULL)
	{
		printf("%scontenido while\n", head->content);
		head = head->next;
	}
}
*/