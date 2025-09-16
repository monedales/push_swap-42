/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:18:53 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/31 20:31:47 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Adds a new node at the beggining of a linked list.
 *
 * Updates the list so that the new node becomes the first element.
 * The 'next' pointer of the new node will point to the previous first node.
 *
 * @param lst A pointer to the pointer of the first node in the list.
 * @param new The node to be added at the front of the list.
 * @return None.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// void	print_list(t_list *head)
// {
// 	int	count = 0;

// 	while (head && count < 50)
// 	{
// 		printf("Conteúdo: %s\n", (char *)head->content);
// 		head = head->next;
// 		count++;
// 	}
// 	if (count == 50)
// 		printf("[⚠️ possível loop infinito detectado]\n");
// }

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew("banana");
// 	t_list *n2 = ft_lstnew("abacate");
// 	t_list *n3 = ft_lstnew("ameixa");
// 	t_list *dup = ft_lstnew(n1->content);

// 	// Lista começa em n1
// 	t_list *lista = n1;
// 	print_list(lista);
// 	// Adiciona n2 no começo da lista
// 	ft_lstadd_front(&lista, n2);
// 	// Esperado: abacate → banana
// 	print_list(lista);
// 	ft_lstadd_front(&lista, n3);
// 	print_list(lista);
// 	ft_lstadd_front(&lista, dup);
// 	print_list(lista);

// 	return (0);
// }
