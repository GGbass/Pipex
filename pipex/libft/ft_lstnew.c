/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:37:39 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/13 10:54:30 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
/*int	main(void)
{
	t_list	*head;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = ft_lstnew(ft_strdup("node"));
	node1 = ft_lstnew(ft_strdup("node1"));
	node2 = ft_lstnew((ft_strdup("node2")));
	head = node;
	node-> next = node1;
	node1-> next = node2;
	while (head != NULL)
	{
		printf("%s\n", head->content);
		head = head->next;
	}

	return (0);
}*/