/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:08:52 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/31 21:30:22 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Creates a new node for a linked list.
 *
 * Allocates memory for a new list node and sets up its fields:
 * -The 'content' field is set to point to the value passed as a parameter.
 * -The 'next' field is initialized to NULL, since the node is not linked to 
 * any other yet.
 *
 * Note: The function does not copy the content; it only stores the pointer.
 * Make sure the data pointed to by 'content' remains valid.
 *
 * @param content A pointer to the data to store inside the new node.
 * @return A pointer to the created node, or NULL if memory allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int main(void)
// {
// 	char	*fruta = "abacaxi";
// 	t_list	*node;
// 	node = ft_lstnew(fruta);
// 	if (node)
// 	{
// 		printf("Conteúdo: %s\n", (char *)node->content);
// 		if (node->next == NULL)
// 			printf("Próximo nó: NULL\n");
// 		else
// 			printf("Próximo nó: %p\n", (void *)node->next);
// 	}
// 	else
// 	{
// 		printf("Erro ao alocar memória para o nó.\n");
// 	}
// 	return (0);
// }