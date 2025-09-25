/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_doubly_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:09:52 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/24 17:53:58 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Creates a new node for a doubly linked list.
 *
 * Allocates memory for a new t_stack node and initializes all its fields.
 * The content is set to the provided value, while next and prev pointers
 * are initialized to NULL, making it ready to be inserted into a list.
 *
 * @param content The integer value to store in the new node.
 * @return A pointer to the newly created node, or NULL if memory allocation fails.
 */
t_stack	*ft_create_node(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * @brief Finds the last node in a doubly linked list.
 *
 * Traverses the list from the head to find the tail node by following
 * the 'next' pointers until reaching a node where next is NULL.
 * This function is useful for operations that need to access the end of the list.
 *
 * @param head A pointer to the first node in the list.
 * @return A pointer to the last node in the list, or NULL if the list is empty.
 */
t_stack	*ft_last_node(t_stack *head)
{
	t_stack	*tail;

	if (!head)
        return (NULL); 
	tail = head;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

/**
 * @brief Adds a new node at the end of a doubly linked list.
 *
 * Appends the new node to the tail of the list. If the list is empty,
 * the new node becomes the head. Otherwise, it updates the 'next' pointer
 * of the current tail and the 'prev' pointer of the new node to maintain
 * the doubly linked structure.
 *
 * @param head A pointer to the pointer of the first node in the list.
 * @param node The node to be added at the end of the list.
 * @return A pointer to the head of the list, or the unchanged head if node is NULL.
 */
t_stack	*ft_add_last(t_stack **head, t_stack *node)
{
	t_stack	*tail;

	if (!node)
		return (*head); // Added to handle NULL head
	if (*head == NULL)
		*head = node;
	else
	{
		tail = ft_last_node(*head);
		node->prev = tail;
		tail->next = node;
	}
	return (*head);
}

/**
 * @brief Adds a new node at the beginning of a doubly linked list.
 *
 * Updates the list so that the new node becomes the first element.
 * The 'next' pointer of the new node will point to the previous first node,
 * and the 'prev' pointer of the previous first node will point to the new node.
 * If the list is empty, the new node becomes the head.
 *
 * @param head A pointer to the pointer of the first node in the list.
 * @param node The node to be added at the front of the list.
 * @return A pointer to the new head of the list, or the unchanged head if node is NULL.
 */
t_stack *ft_add_front(t_stack **head, t_stack *node)
{
	if (!node)
		return (*head);
	if (*head == NULL)
		*head = node;
	else
	{
		node->next = *head;
		(*head)->prev = node; //higher precedence so we need parentheses
		*head = node;
	}
	return (*head);
}

/**
 * @brief Calculates the number of nodes in a doubly linked list.
 *
 * Traverses the entire list from head to tail by following the 'next' pointers,
 * counting each node encountered. This function provides the size/length of
 * the list without modifying its structure.
 *
 * @param head A pointer to the first node in the list.
 * @return The number of nodes in the list as ssize_t, or 0 if the list is empty.
 */
ssize_t	ft_list_size(t_stack *head)
{
	ssize_t	len;
	t_stack	*temp;
	
	if (!head)
		return (0);
	len = 0;
	temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
