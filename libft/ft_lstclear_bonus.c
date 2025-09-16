/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:54:35 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/01 19:38:49 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Deletes and frees a node and all its successors in a linked list.
 *
 * This function deletes the given node and every node that follows it in the 
 * list. It uses the 'del' function to free the content of each node and 
 * free() to deallocate the nodes themselves. Finally, it sets the pointer to 
 * the list to NULL.
 *
 * @param lst A pointer to the pointer of the first node to delete.
 * @param del A function pointer used to free the content of each node.
 * @return None.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*keep;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		keep = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = keep;
	}
	*lst = NULL;
}

// int main(void)
// {
// 	char	*n1 = "um";
// 	char	*n2 = "dois";
// 	char	*n3 = "três";
// 	char	*n4 = "quatro";
// 	char	*n5 = "cinco";
// 	//coloca o n1 como nó, no começo da lista
// 	t_list	*lista = ft_lstnew(n1);
// 	//adiciona nós do segundo em diante na mesma lista
// 	ft_lstadd_back(&lista, ft_lstnew(n2));
// 	ft_lstadd_back(&lista, ft_lstnew(n3));
// 	ft_lstadd_back(&lista, ft_lstnew(n4));
// 	ft_lstadd_back(&lista, ft_lstnew(n5));

// 	// antes de deletar os nós, é necessário cortar 
// 	//a conexão do segundo para o terceiro nó
// 	t_list *second = lista->next;
// 	t_list *third = second->next;
// 	second->next = NULL;
// 	//limpando a partir do terceiro nó
// 	ft_lstclear(&third, del_content);
// 	t_list *tmp = lista;
// 	while (tmp)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}

// 	printf("NULL\n");
// 	return (0);
// }