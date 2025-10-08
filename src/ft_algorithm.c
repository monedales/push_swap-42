/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:35:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/08 15:30:10 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Push elements from current chunk to stack B.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param chunk_min Minimum index for current chunk.
 * @param chunk_max Maximum index for current chunk.
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
 * @brief Push all elements back from B to A using cost-based Turk algorithm.
 *
 * Finds the cheapest element to move from B to A based on rotation costs,
 * then executes the optimal move to place it in the correct position.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
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
 * @brief Chunk-based Turk Algorithm implementation for large arrays.
 *
 * Pushes elements to B in chunks, sorts remaining 3 in A, pushes back
 * from B to A using cost-based selection, then rotates minimum to top.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
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
