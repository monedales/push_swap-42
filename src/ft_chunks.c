/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:27:18 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/07 15:35:18 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Calculate optimal chunk size based on stack size.
 *
 * @param stack_size Total number of elements in stack.
 * @return Optimal chunk size for processing.
 */
int	ft_get_chunk_size(int stack_size)
{
	if (stack_size <= 50)
		return (10);
	else if (stack_size <= 100)
		return (25);
	else if (stack_size <= 500)
		return (70);
	else
		return (70);
}

/**
 * @brief Check if element belongs to current chunk range.
 *
 * @param element Pointer to element to check.
 * @param chunk_min Minimum index for current chunk.
 * @param chunk_max Maximum index for current chunk.
 * @return 1 if element is in chunk, 0 otherwise.
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
 * @brief Find best element from current chunk to move to B.
 *
 * @param stack_a Pointer to stack A.
 * @param chunk_min Minimum index for current chunk.
 * @param chunk_max Maximum index for current chunk.
 * @return Pointer to best element, or NULL if none found.
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
