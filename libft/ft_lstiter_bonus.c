/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:04:32 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/01 18:39:53 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Apply a function to each node's content from a linked list.
 *
 * This function iterates over the whole list and applies the function 'f' 
 * to the content of each node.
 * 
 * @param lst The pointer address to one node.
 * @param f A function pointer to be applied to each node's content.
 * @return None.
 */
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

// void	upcase(void *content)
// {
// 	char	*str = (char *)content;
// 	while (*str)
// 	{
// 		if (*str >= 'a' && *str <= 'z')
// 			*str -= 32;
// 		str++;
// 	}
// }
// int	main(void)
// {
// 	t_list	*lista;
// 	char	*s1 = strdup("um");
// 	char	*s2 = strdup("dois");
// 	char	*s3 = strdup("tres");
// 	lista = ft_lstnew(s1);
// 	ft_lstadd_back(&lista, ft_lstnew(s2));
// 	ft_lstadd_back(&lista, ft_lstnew(s3));
// 	printf("Antes:\n");
// 	t_list *tmp = lista;
// 	while (tmp)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// 	ft_lstiter(lista, upcase);
// 	printf("Depois:\n");
// 	tmp = lista;
// 	while (tmp)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// 	return (0);
// }