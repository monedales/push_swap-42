/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_doubly_list2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:22:52 by mona              #+#    #+#             */
/*   Updated: 2025/09/24 19:17:57 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *head)
{
    t_stack *temp;
    
    if (head == NULL) 
    {
        ft_printf("The list is empty.\n");
        return ;
    }
    temp = head;
    while(temp != NULL)
    {
        ft_printf("%d \n", temp->content);
        temp = temp->next;
    }
    ft_printf("\n");
}

t_stack *ft_remove_first(t_stack **head)
{
    t_stack *removed_node;
    
    if (*head == NULL)
        return (NULL);
    removed_node = *head; // Store the node to remove
    *head = (*head)->next; // Update head to point to second node
    if (*head != NULL)
        (*head)->prev = NULL;
    removed_node->next = NULL;
    removed_node->prev = NULL;
    return (removed_node);
}

t_stack *ft_remove_last(t_stack **head)
{
	t_stack *removed_node;
	
    if (*head == NULL) //if list is already empty
        return (NULL);
	removed_node = ft_last_node(*head); //find the tail
	if (removed_node->prev != NULL) //if its NOT a single node list, point the prev to null
        removed_node->prev->next = NULL;
	else
		*head = NULL; //if its a single node list, now the list is empty
	removed_node->next = NULL; //disconnect the node from the list
    removed_node->prev = NULL;
	return (removed_node);
}