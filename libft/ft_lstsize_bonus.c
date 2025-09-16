/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:08:38 by maria-ol          #+#    #+#             */
/*   Updated: 2025/07/31 21:30:14 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Counts the number of nodes in a linked list.
 *
 * Traverses the list from the given starting node, counting each node until it 
 * reaches the end (NULL).
 *
 * @param lst A pointer to the first node of the list.
 * @return The total number of nodes in the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*temp;

	len = 0;
	temp = lst;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

// void	print_list(t_list *lst)
// {
// 	t_list *tmp = lst;
// 	while (tmp)
// 	{
// 		printf("Content: %s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// }
// int	main(void)
// {
// 	t_list *n1 = ft_lstnew("banana");
// 	t_list *n2 = ft_lstnew("abacate");
// 	t_list *n3 = ft_lstnew("ameixa");
// 	t_list *lista = n1;
// 	print_list(lista);
// 	ft_lstadd_front(&lista, n2); // abacate -> banana
// 	print_list(lista);
// 	ft_lstadd_front(&lista, n3); // ameixa -> abacate -> banana
// 	print_list(lista);
// 	int size = ft_lstsize(lista);
// 	printf("Tamanho da lista: %d\n", size);
// 	return (0);
// }