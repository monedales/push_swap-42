/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:42:02 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/01 15:01:49 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Deletes a single node from the list.
 *
 * Frees the memory of the given node’s content using the function 'del', 
 * then frees the node itself. The pointer to the next node is not affected.
 *
 * @param lst The node to delete.
 * @param del A function pointer to free the content of the node.
 * @return None.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del_content(void *content)
// {
// 	printf("Liberando o conteúdo: %s\n", (char *)content);
// 	// free(content);
// }
// int	main(void)
// {
// 	t_list	*node;
// 	char	*fruit = ft_strdup("banana");
// 	char	*fruit2 = ft_strdup("amora");
// 	t_list	*lista = NULL;

// 	if (!fruit || !fruit2)
// 		return (1);

// 	node = ft_lstnew(fruit);
// 	if (!node)
// 	{
// 		free(fruit);
// 		return (1);
// 	}

// 	// Criar uma lista com dois nós
// 	ft_lstadd_back(&lista, node);
// 	ft_lstadd_back(&lista, ft_lstnew(fruit2));
// 	// Imprimir antes de deletar
// 	t_list *tmp = lista;
// 	while (tmp)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// 	// Testar a função de deletar só o primeiro nó
// 	ft_lstdelone(node, del_content);

// 	return (0);
// }