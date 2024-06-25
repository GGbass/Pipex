/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:21:59 by gongarci          #+#    #+#             */
/*   Updated: 2024/03/13 18:51:07 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!*lst)
		*lst = new;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
	}
}
/*int	main()
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew(ft_strdup("node1"));
	ft_lstadd_front(&head, node1);
	node2 = ft_lstnew(ft_strdup("node2"));
	ft_lstadd_front(&head, node2);
	node3 = ft_lstnew(ft_strdup("node3"));
	ft_lstadd_front(&head, node3);

	while (head != NULL && head != node1)
	{
		ft_lstadd_back(&head, node3);
		printf("%s\n", head->content);
		head = head->next;

		ft_lstadd_back(&head, node2);
		printf("%s\n", head->content);
		head = head->next;

		ft_lstadd_back(&head, node1);
		printf("%s\n", head->content);
		head = head->next;
	}

	printf("nada\n");
	return (0);
}
*/