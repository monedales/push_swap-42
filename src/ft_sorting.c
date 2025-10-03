/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:00:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/03 17:18:35 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Sorts exactly 2 elements in stack A using minimal operations.
 *
 * Checks if the first element is greater than the second and swaps them
 * if necessary. This requires at most 1 operation (sa).
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 */
void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

/**
 * @brief Sorts exactly 3 elements in stack A using minimal operations.
 *
 * Uses optimized conditional logic to sort 3 elements with at most 3 operations.
 * Covers all possible arrangements of 3 numbers to achieve minimal ops.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
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
 * Rotates stack A to bring the minimum element to the top position,
 * choosing the most efficient rotation direction.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_size Current size of stack A.
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
 * Strategy: Push the smallest elements to stack B, sort the remaining
 * elements in stack A, then push back from B.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
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
 * @brief Main sorting dispatch function.
 *
 * Determines the appropriate sorting algorithm based on the stack size
 * and delegates to the optimal function for each case.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
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
