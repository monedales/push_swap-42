/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:33:16 by maria-ol          #+#    #+#             */
/*   Updated: 2025/08/01 12:23:49 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Returns the last node of the linked list.
 *
 * This function receives the first node of a linked list and traverses
 * it until it reaches the last node (the one whose 'next' is NULL).
 *
 * @param lst A pointer to the first node of the list.
 * @return A pointer to the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while ((*last).next != NULL)
		last = last->next;
	return (last);
}
// int main(void)
// {
// 	t_list *n1 = ft_lstnew("banana");
// 	t_list *n2 = ft_lstnew("abacate");
// 	t_list *n3 = ft_lstnew("ameixa");
// 	n1->next = n2;
// 	n2->next = n3;
// 	t_list *last = ft_lstlast(n3);
// 	if (last)
// 		printf("Último nó: %s\n", (char *)last->content);
// 	else
// 		printf("A lista está vazia.\n");
// 	return (0);
// }