/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:00 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/17 14:17:32 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*static	void	ft_print_node(void *content)
{
	printf("%s ", content);
}*/

/*int	main(void)
{
	t_list	*head;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = ft_lstnew(ft_strdup("node"));
	head = node;
	node1 = ft_lstnew(ft_strdup("node1"));
	head = node1;
	node2 = ft_lstnew(ft_strdup("node2"));
	head = node2;
	ft_lstiter(head, ft_print_node);
	printf("\n");
	return (0);
}
*/