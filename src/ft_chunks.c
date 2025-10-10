/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:27:18 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 17:26:43 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Determines the optimal chunk size for dividing the stack.
 * 
 * Defines how many elements should be processed per chunk during
 * the push-swap algorithm. Smaller stacks use fewer chunks for
 * efficiency, while larger stacks benefit from more granular division.
 *
 * @param stack_size Total number of elements in stack.
 * @return Optimal chunk size for processing.
 */
int	ft_get_chunk_size(int stack_size)
{
	if (stack_size <= 50)
		return (10);
	else if (stack_size <= 100)
		return (23);
	else if (stack_size <= 500)
		return (70);
	else
		return (70);
}

/**
 * @brief Check if element belongs to current chunk range.
 *
 * Verifies if the element's index falls between the defined chunk
 * boundaries. Used to decide which elements should be pushed to
 * stack B during chunk-based partitioning.
 * 
 * @param element Pointer to element to be checked.
 * @param chunk_min Minimum index value defining the current chunk.
 * @param chunk_max Maximum index value defining the current chunk.
 * @return 1 if the element is within the chunk range, 0 otherwise.
 *
 * @see ft_get_chunk_size()
 */
int	ft_in_chunk(t_stack *element, int chunk_min, int chunk_max)
{
	if (!element)
		return (0);
	if (element->index >= chunk_min && element->index <= chunk_max)
		return (1);
	return (0);
}

/**
 * @brief Find best element from current chunk to rotate in stack A.
 *
 * Iterates through stack A to locate an element whose index is within the
 * range [chunk_min, chunk_max] and has the minimal rotation cost to reach
 * the top of the stack.
 *
 * @param stack_a Pointer to the head of stack A.
 * @param chunk_min Minimum index of the current chunk.
 * @param chunk_max Maximum index of the current chunk.
 * @return Pointer to the element with the lowest rotation cost, 
 * or NULL if no element is found.
 */
t_stack	*ft_find_chunk_element(t_stack *stack_a, int chunk_min, int chunk_max)
{
	t_stack	*current;
	t_stack	*best;
	int		best_cost;
	int		current_cost;

	if (!stack_a)
		return (NULL);
	current = stack_a;
	best = NULL;
	best_cost = MAX_INT;
	while (current)
	{
		if (ft_in_chunk(current, chunk_min, chunk_max))
		{
			current_cost = ft_calc_ra(stack_a, current);
			if (current_cost < best_cost)
			{
				best_cost = current_cost;
				best = current;
			}
		}
		current = current->next;
	}
	return (best);
}
