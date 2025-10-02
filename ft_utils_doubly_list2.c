/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_doubly_list2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:22:52 by mona              #+#    #+#             */
/*   Updated: 2025/10/02 17:36:14 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints all elements in a doubly linked list stack.
 *
 * Traverses the stack from head to tail, printing each node's content
 * followed by a newline. If the stack is empty, prints an informative
 * message. This function is useful for debugging and visualizing stack
 * contents during development.
 *
 * @param head A pointer to the first node in the stack.
 */
void	print_stack(t_stack *head)
{
	t_stack	*temp;

	if (head == NULL)
	{
		ft_printf("The list is empty.\n");
		return ;
	}
	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d \n", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}

/**
 * @brief Removes and returns the first node from a doubly linked list.
 *
 * Detaches the head node from the list by updating the head pointer to
 * the second node and properly disconnecting all links. The removed node
 * is isolated (next and prev set to NULL) and returned for further use.
 * Safely handles empty lists by returning NULL.
 *
 * @param head A pointer to the pointer of the first node in the list.
 * @return The removed node, or NULL if the list is empty.
 */
t_stack	*ft_remove_first(t_stack **head)
{
	t_stack	*removed_node;

	if (!head || !*head)
		return (NULL);
	removed_node = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	removed_node->next = NULL;
	removed_node->prev = NULL;
	return (removed_node);
}

/**
 * @brief Removes and returns the last node from a doubly linked list.
 *
 * Finds the tail node using ft_last_node() and detaches it from the list
 * by updating the previous node's next pointer. Handles both single-node
 * lists (updates head to NULL) and multi-node lists (updates prev->next).
 * The removed node is isolated and returned for further use.
 *
 * @param head A pointer to the pointer of the first node in the list.
 * @return The removed tail node, or NULL if the list is empty.
 */
t_stack	*ft_remove_last(t_stack **head)
{
	t_stack	*removed_node;

	if (!head || !*head)
		return (NULL);
	removed_node = ft_last_node(*head);
	if (removed_node->prev != NULL)
		removed_node->prev->next = NULL;
	else
		*head = NULL;
	removed_node->next = NULL;
	removed_node->prev = NULL;
	return (removed_node);
}

/**
 * @brief Finds the position of the minimum element in the stack.
 *
 * Iterates through the stack to find the node with the smallest content value
 * and returns its position (0-indexed) from the top of the stack.
 *
 * @param stack Pointer to the first node in the stack.
 * @return Position of the minimum element (0-indexed).
 */
int	ft_find_min_position(t_stack *stack)
{
	int		min_value;
	int		min_position;
	int		current_position;

	if (!stack)
		return (-1);
	min_value = stack->content;
	min_position = 0;
	current_position = 0;
	while (stack)
	{
		if (stack->content < min_value)
		{
			min_value = stack->content;
			min_position = current_position;
		}
		stack = stack->next;
		current_position++;
	}
	return (min_position);
}
