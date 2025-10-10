/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:00:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 16:44:12 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Sorts exactly two elements in stack A using a single operation.
 *
 * Compares the first two elements in stack A and swaps them if the first
 * is greater than the second. This guarantees the stack is sorted in
 * ascending order with at most one operation (sa).
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 */
void	ft_sort_two(t_stack **stack_a)
{
	int	first;
	int	second;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	if (first > second)
		ft_sa(stack_a);
}

/**
 * @brief Sorts exactly 3 elements in stack A using minimal operations.
 *
 * 	Handles all six possible orderings of three elements, applying the
 * optimal combination of operations (sa, ra, rra) to achieve a sorted
 * ascending sequence. Guarantees sorting in at most three operations.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @see See also: ft_sa, ft_ra, ft_rra
 */
void	ft_sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
		ft_sa(stack_a);
	else if (first > second && second > third)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ft_ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		ft_rra(stack_a);
}

/**
 * @brief Moves the minimum element to the top of stack A.
 *
 * Finds the position of the smallest element in the stack and rotates
 * it to the top, choosing the shortest direction (ra or rra) based on
 * its position relative to the stack size.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_size Current size of stack A.
 * @see See also: ft_find_min_position, ft_ra, ft_rra
 */
void	ft_move_min_to_top(t_stack **stack_a, int stack_size)
{
	int	min_pos;

	min_pos = ft_find_min_position(*stack_a);
	if (min_pos <= stack_size / 2)
	{
		while (min_pos-- > 0)
			ft_ra(stack_a);
	}
	else
	{
		while (min_pos++ < stack_size)
			ft_rra(stack_a);
	}
}

/**
 * @brief Sorts 4 or 5 elements using optimized algorithm.
 *
 * Pushes the smallest elements to stack B, sorts the remaining 3 elements
 * in stack A, and then pushes everything back to stack A in sorted order.
 * This approach minimizes the number of moves while ensuring correctness.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
 * 
 * @see See also: ft_move_min_to_top, ft_pb, ft_pa, ft_sort_two, ft_sort_three
 */
void	ft_sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_list_size(*stack_a);
	while (stack_size > 3)
	{
		ft_move_min_to_top(stack_a, stack_size);
		ft_pb(stack_a, stack_b);
		stack_size--;
	}
	if (stack_size == 2)
		ft_sort_two(stack_a);
	else if (stack_size == 3)
		ft_sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

/**
 * @brief Main sorting dispatcher selecting the optimal algorithm.
 *
 * Determines the best sorting routine to use based on the current stack size:
 * - 2 elements → simple swap
 * - 3 elements → optimized triple sort
 * - 4-5 elements → small sort using stack B
 * - >5 elements → full sorting algorithm (Turk-Chunk algorithm)
 *
 * Automatically skips sorting if the stack is already sorted.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
 * 
 * @see See also: ft_sort_two, ft_sort_three, ft_sort_small
 * @see See also: ft_turk_algorithm, ft_is_sorted
 */
void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	if (!stack_a || !*stack_a || ft_is_sorted(*stack_a))
		return ;
	stack_size = ft_list_size(*stack_a);
	if (stack_size == 2)
		ft_sort_two(stack_a);
	else if (stack_size == 3)
		ft_sort_three(stack_a);
	else if (stack_size <= 5)
		ft_sort_small(stack_a, stack_b);
	else
		ft_turk_algorithm(stack_a, stack_b);
}
