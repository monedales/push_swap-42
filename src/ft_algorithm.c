/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:35:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 20:10:40 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Push all elements from the current chunk in stack A to stack B.
 *
 * Iterates through stack A and moves elements belonging to the current chunk
 * (between `chunk_min` and `chunk_max`) to stack B. The element closest to 
 * the top of stack A is moved first to minimize rotations. 
 * 
 * Elements in the lower half of the chunk (below `mid_chunk`) are rotated 
 * within stack B after being pushed, to optimize the order for future moves.
 *
 * @param stack_a Pointer to the head pointer of stack A.
 * @param stack_b Pointer to the head pointer of stack B.
 * @param chunk_min Minimum index for the current chunk.
 * @param chunk_max Maximum index for the current chunk.
 */
static void	ft_push_chunk_to_b(t_stack **stack_a, t_stack **stack_b,
				int chunk_min, int chunk_max)
{
	t_stack	*element;
	int		mid_chunk;

	mid_chunk = chunk_min + (chunk_max - chunk_min) / 2;
	while (1)
	{
		element = ft_find_chunk_element(*stack_a, chunk_min, chunk_max);
		if (!element)
			break ;
		ft_rotate_a_to_top(stack_a, element);
		ft_pb(stack_a, stack_b);
		if ((*stack_b)->index < mid_chunk && ft_list_size(*stack_b) > 1)
			ft_rb(stack_b);
	}
}

/**
 * @brief Push all elements back from stack B to stack A.
 *
 * Iteratively moves elements from stack B to their correct positions in stack A.
 * For each element, finds the cheapest move based on combined rotation costs,
 * then executes the optimal sequence of rotations and push operations.
 *
 * @param stack_a Pointer to the head pointer of stack A.
 * @param stack_b Pointer to the head pointer of stack B.
 */
static void	ft_push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while (*stack_b)
	{
		cheapest = ft_cheapest_b_to_a(*stack_a, *stack_b);
		ft_best_move_b_to_a(stack_a, stack_b, cheapest);
	}
}

/**
 * @brief Chunk-based Turk algorithm for sorting larger stacks.
 *
 * Implements a divide-and-conquer strategy:
 * 1. Divides stack A into chunks and pushes each chunk to B.
 * 2. Sorts the remaining three elements in stack A.
 * 3. Pushes all elements back from B to A using cost-based selection.
 * 4. Rotates stack A to place the smallest element on top.
 *
 * @param stack_a Pointer to the head pointer of stack A.
 * @param stack_b Pointer to the head pointer of stack B.
 * @note Assumes stack size is greater than 5. For smaller stacks,
 *       simpler sorting functions should be used.
 */
void	ft_turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int		stack_size;
	int		chunk_size;
	int		chunk_min;
	int		chunk_max;
	t_stack	*min_elem;

	if (!stack_a || !*stack_a || ft_list_size(*stack_a) <= 5)
		return ;
	stack_size = ft_list_size(*stack_a);
	chunk_size = ft_get_chunk_size(stack_size);
	chunk_min = 0;
	while (ft_list_size(*stack_a) > 3)
	{
		chunk_max = chunk_min + chunk_size - 1;
		if (chunk_max >= stack_size - 3)
			chunk_max = stack_size - 4;
		if (chunk_min >= stack_size - 3)
			break ;
		ft_push_chunk_to_b(stack_a, stack_b, chunk_min, chunk_max);
		chunk_min += chunk_size;
	}
	ft_sort_three(stack_a);
	ft_push_back_to_a(stack_a, stack_b);
	min_elem = ft_find_min_element(*stack_a);
	ft_rotate_a_to_top(stack_a, min_elem);
}
