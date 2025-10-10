/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:15:06 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 18:18:36 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// /**
//  * @brief Prints all elements in a doubly linked list stack.
//  *
//  * Traverses the stack from head to tail, printing each node's content
//  * followed by a newline. If the stack is empty, prints an informative
//  * message. This function is useful for debugging and visualizing stack
//  * contents during development.
//  *
//  * @param head A pointer to the first node in the stack.
//  */
// void	print_stack(t_stack *head)
// {
// 	t_stack	*temp;

// 	if (head == NULL)
// 	{
// 		ft_printf("The list is empty.\n");
// 		return ;
// 	}
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		ft_printf("%d \n", temp->content);
// 		temp = temp->next;
// 	}
// 	ft_printf("\n");
// }
