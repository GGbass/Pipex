/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:22:11 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/27 13:43:06 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*head;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = ft_lstnew(ft_strdup("node"));
	node1 = ft_lstnew(ft_strdup("node1"));
	node2 = ft_lstnew(ft_strdup("node2"));
	while (head != NULL)
	{
		ft_lstadd_front(&head, node);
		printf("%s\n", head->content);
		ft_lstadd_front(&head, node1);
		printf("%s\n", head->content);
		ft_lstadd_front(&head, node2);
		printf("%s\n", head->content);
	}
	return (0);
}*/
