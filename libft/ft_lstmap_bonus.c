/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:54:21 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/01 19:45:40 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Creates a new list by applying a function to each node's content.
 *
 * Iterates through the list 'lst', applies the function 'f' to the content of 
 * each node, and creates a new list from the results of these function 
 * applications. The 'del' function is used to free the content of any node 
 * if an allocation fails.
 *
 * @param lst A pointer to the pointer of list.
 * @param f A function pointer to be applied to each node's content.
 * @param del A function pointer used to free the content of each node.
 * @return The new list, or NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*list;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		node = ft_lstnew(new_content);
		if (!node)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		lst = lst->next;
	}
	return (list);
}

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }
// void	free_content(void *content)
// {
// 	free(content);
// }
// void	*to_uppercase(void *content)
// {
// 	char	*str = (char *)content;
// 	char	*upper = strdup(str);
// 	int		i = 0;
// 	if (!upper)
// 		return (NULL);
// 	while (upper[i])
// 	{
// 		if (upper[i] >= 'a' && upper[i] <= 'z')
// 			upper[i] -= 32;
// 		i++;
// 	}
// 	return (upper);
// }
// int	main(void)
// {
// 	t_list	*original = ft_lstnew(strdup("oi"));
// 	ft_lstadd_back(&original, ft_lstnew(strdup("tudo")));
// 	ft_lstadd_back(&original, ft_lstnew(strdup("bem")));
// 	t_list *upper = ft_lstmap(original, to_uppercase, free_content);
// 	print_list(original);
// 	print_list(upper);
// 	ft_lstclear(&original, free_content);
// 	ft_lstclear(&upper, free_content);
// }