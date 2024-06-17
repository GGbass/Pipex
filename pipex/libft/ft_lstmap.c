/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:23:50 by gongarci          #+#    #+#             */
/*   Updated: 2023/10/30 20:28:21 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	void	*aux;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		aux = f(lst->content);
		new_element = ft_lstnew(aux);
		if (!new_element)
		{
			del(aux);
			ft_lstclear(&new_element, del);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}

/*static	char	*ft_str_toupper(char *str)
{
	char		*str1;
	int			i;

	str1 = ft_strdup(str);
	i = 0;
	while (str1[i] != '\0')
	{
		str1[i] = ft_toupper(str1[i]);
		i++;
	}
	return (str1);
}*/

/*int	main()
{
	t_list	*head;
	t_list	*lista;

	head = ft_lstnew(ft_strdup("hola"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("como")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("estas")));
	lista = ft_lstmap(head, (void *)ft_str_toupper, free);
	while (lista != NULL)
	{
		printf("%s\n", lista->content);
		lista = lista->next;
	}
	printf("\n");
	ft_lstclear(&lista, free);
	ft_lstclear(&head, free);
	return (0);
}
*/