/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:10:04 by mona              #+#    #+#             */
/*   Updated: 2025/09/29 19:21:58 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/**
 * @brief Frees all nodes in a doubly linked list and sets the head pointer 
 * to NULL.
 *
 * Traverses the entire list from head to tail, freeing each node's memory
 * and properly updating the head pointer. After execution, the stack pointer
 * will be set to NULL, ensuring no dangling pointers remain. This function
 * safely handles empty lists and NULL pointers.
 *
 * @param stack A pointer to the pointer of the first node in the list.
 *              After execution, this will be set to NULL.
 */
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

// void	clean_args(char **args, int should_free, int word_count)
// {
// 	if (should_free)
// 		ft_free_arr(args, word_count);
// }
