/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:00:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 20:10:13 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Rotate stack A to bring a target element to the top efficiently.
 *
 * Chooses the rotation direction that requires fewer operations and
 * rotates stack A until the target element reaches the top.
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
 * @brief Execute the optimal move from stack B to stack A.
 *
 * Calculates rotation costs for both stacks and performs the element transfer
 * efficiently. Uses combined rotations (`rr` / `rrr`) when both stacks rotate
 * in the same direction to minimize operations, then completes any remaining
 * individual rotations before pushing the element from B to A.
 *
 * @param stack_a Pointer to the head pointer of stack A.
 * @param stack_b Pointer to the head pointer of stack B.
 * @param element Pointer to the element in B to move to A.
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
 * @brief Find the appropriate target element in stack A for insertion from B.
 *
 * Iterates through stack A to locate the element where a given value from
 * stack B should be inserted to maintain sorted order. If the value is
 * larger than all elements in A, returns the smallest element (wrap-around).
 *
 * @param stack_a Pointer to the head of stack A.
 * @param value Value from stack B to insert into stack A.
 * @return Pointer to the target element in stack A for insertion.
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

/**
 * @brief Get the 0-indexed position of a target element in a stack.
 *
 * Iterates through the stack to find the specified target element and
 * returns its position counting from the head of the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @param target Pointer to the element to find.
 * @return Position of the element (0-indexed), or -1 if it's not in the stack.
 */
int	ft_get_position(t_stack *stack, t_stack *target)
{
	t_stack	*current;
	int		position;

	if (!stack || !target)
		return (-1);
	current = stack;
	position = 0;
	while (current)
	{
		if (current == target)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

/**
 * @brief Find element with minimum index in stack.
 *
 * Iterates through the stack to find the element with the lowest index.
 * Useful for final rotation to place the smallest element at the top.
 *
 * @param stack Pointer to the head of the stack.
 * @return Pointer to the element with the minimum index, 
 * - or NULL if stack is empty.
 */
t_stack	*ft_find_min_element(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_element;

	if (!stack)
		return (NULL);
	current = stack;
	min_element = current;
	while (current)
	{
		if (current->index < min_element->index)
			min_element = current;
		current = current->next;
	}
	return (min_element);
}
