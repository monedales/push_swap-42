/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/07 14:18:03 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Rotate stack A to bring target element to top.
 *
 * Uses the most efficient rotation direction to bring the specified
 * element to the top of stack A.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param target Pointer to element to bring to top.
 */
void	ft_rotate_a_to_top(t_stack **stack_a, t_stack *target)
{
	int	cost;
	int	rotate_up;
	int	i;

	cost = ft_efficient_rotation_cost(*stack_a, target);
	rotate_up = ft_should_rotate_up(*stack_a, target);
	i = 0;
	while (i < cost)
	{
		if (rotate_up)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
		i++;
	}
}

/**
 * @brief Execute optimal move from B to A with combined rotations.
 *
 * Calculates rotation costs for both stacks, uses combined operations
 * (rr/rrr) when both rotate in same direction to reduce total operations,
 * then performs remaining individual rotations before pushing from B to A.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param element Pointer to element to move from B to A.
 */
void	ft_best_move_b_to_a(t_stack **stack_a, t_stack **stack_b,
			t_stack *element)
{
	t_stack	*target_a;
	int		costs[3];
	int		rotate_up_b;

	if (!element)
		return ;
	target_a = ft_find_target_in_a(*stack_a, element->index);
	costs[0] = ft_efficient_rotation_cost(*stack_a, target_a);
	costs[1] = ft_efficient_rotation_cost(*stack_b, element);
	costs[2] = ft_should_rotate_up(*stack_a, target_a);
	rotate_up_b = ft_should_rotate_up(*stack_b, element);
	if (costs[2] == rotate_up_b)
		ft_apply_combined_rotations(stack_a, stack_b, costs);
	ft_individual_rotations_a(stack_a, costs[0], costs[2]);
	ft_individual_rotations_b(stack_b, costs[1], rotate_up_b);
	ft_pa(stack_a, stack_b);
}

/**
 * @brief Find target element in A for insertion from B.
 *
 * @param stack_a Stack A.
 * @param value Value to find target for.
 * @return Pointer to target element in A.
 */
t_stack	*ft_find_target_in_a(t_stack *stack_a, int value)
{
	t_stack	*current;
	t_stack	*best_match;
	t_stack	*min_element;

	if (!stack_a)
		return (NULL);
	current = stack_a;
	best_match = NULL;
	min_element = stack_a;
	while (current)
	{
		if (current->index < min_element->index)
			min_element = current;
		if (current->index > value
			&& (!best_match || current->index < best_match->index))
			best_match = current;
		current = current->next;
	}
	if (!best_match)
		best_match = min_element;
	return (best_match);
}