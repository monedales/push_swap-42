/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:43:58 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/01 12:41:41 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Adds a new node at the end of a linked list.
 *
 * If the list is not empty, this function finds the last node and sets its 
 * 'next' pointer to the new node.
 * If the list is empty, the new node becomes the first node.
 *
 * @param lst A pointer to the pointer of the first node in the list.
 * @param new The node to be added at the end of the list.
 * @return None.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
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
// int main(void)
// {
// 	t_list *n1 = ft_lstnew("banana");
// 	t_list *n2 = ft_lstnew("abacate");
// 	t_list *n3 = ft_lstnew("ameixa");
// 	t_list *lista = NULL;
// 	// Testa adicionar na lista vazia
// 	ft_lstadd_back(&lista, n1);
// 	print_list(lista);  // Esperado: banana -> NULL
// 	// Testa adicionar mais elementos
// 	ft_lstadd_back(&lista, n2);
// 	ft_lstadd_back(&lista, n3);
// 	print_list(lista);  // Esperado: banana -> abacate -> ameixa -> NULL
// 	return (0);
// }