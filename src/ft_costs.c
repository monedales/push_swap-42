/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/10 18:20:08 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Calculate cost to rotate element to top of stack A.
 *
 * Determines the minimum number of operations needed to bring a target
 * element to the top of stack A. Compares rotate up (ra) vs rotate
 * down (rra) and returns the cheaper option.
 *
 * @param stack_a Pointer to the first node of stack A.
 * @param target Pointer to the target element to move to top.
 * @return Cost in operations to bring target to top.
 */
int	ft_calc_ra(t_stack *stack_a, t_stack *target)
{
	t_stack	*current;
	int		position;
	int		stack_size;
	int		cost_up;
	int		cost_down;

	if (!stack_a || !target)
		return (0);
	position = 0;
	current = stack_a;
	while (current && current != target)
	{
		position++;
		current = current->next;
	}
	stack_size = ft_list_size(stack_a);
	cost_up = position;
	cost_down = stack_size - position;
	if (cost_up <= cost_down)
		return (cost_up);
	return (cost_down);
}

/**
 * @brief Calculate the rotation cost to bring a element to the top of the stack.
 *
 * Computes the number of operations needed to move the target element to the top
 * by comparing rotating upwards (towards the head) versus
 * rotating downwards (towards the tail) and returning the smaller cost.
 *
 * @param stack Pointer to the head of the stack.
 * @param target Pointer to the element to move to the top.
 * @return Minimum number of rotations required to bring the target to the top.
 */
int	ft_efficient_rotation_cost(t_stack *stack, t_stack *target)
{
	int	position;
	int	stack_size;
	int	cost_up;
	int	cost_down;

	position = ft_get_position(stack, target);
	if (position == -1)
		return (0);
	stack_size = ft_list_size(stack);
	cost_up = position;
	cost_down = stack_size - position;
	if (cost_up <= cost_down)
		return (cost_up);
	return (cost_down);
}

/**
 * @brief Determine whether it is more efficient to rotate up or down.
 *
 * Checks whether the target element is in the first or second half of the stack.
 * Returns 1 if rotating upwards (towards the head) is more efficient,
 * or 0 if rotating downwards (towards the tail) is more efficient.
 *
 * @param stack Pointer to the head of the stack.
 * @param target Pointer to the element to move to the top.
 * @return 1 if rotating up is more efficient, 0 if rotating down.
 */
int	ft_should_rotate_up(t_stack *stack, t_stack *target)
{
	int	position;
	int	stack_size;

	position = ft_get_position(stack, target);
	if (position == -1)
		return (1);
	stack_size = ft_list_size(stack);
	if (position <= stack_size / 2)
		return (1);
	else
		return (0);
}

/**
 * @brief Calculate the total cost to move an element from stack B to stack A.
 *
 * Computes the total number of operations needed to move a given element
 * from stack B to its correct position in stack A. This includes:
 * 1. Rotating stack B to bring the element to the top.
 * 2. Rotating stack A to prepare the correct insertion position.
 *
 * @param stack_a Pointer to the head of stack A.
 * @param stack_b Pointer to the head of stack B.
 * @param element Pointer to the element in B to move.
 * @return Total number of rotations required to move the element to A.
 */
int	ft_calc_cost_b_to_a(t_stack *stack_a, t_stack *stack_b, t_stack *element)
{
	t_stack	*target_a;
	int		cost_b;
	int		cost_a;

	if (!element)
		return (0);
	target_a = ft_find_target_in_a(stack_a, element->index);
	cost_b = ft_efficient_rotation_cost(stack_b, element);
	cost_a = ft_efficient_rotation_cost(stack_a, target_a);
	return (cost_a + cost_b);
}

/**
 * @brief Find the cheapest element in stack B to move to stack A.
 *
 * Iterates through stack B and calculates the total cost to move each element
 * to its correct position in stack A. Returns the element with the lowest
 * total cost, which minimizes the number of required operations.
 *
 * @param stack_a Pointer to the head of stack A.
 * @param stack_b Pointer to the head of stack B.
 * @return Pointer to the element in B with the lowest total move cost.
 */
t_stack	*ft_cheapest_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_cost;
	int		current_cost;

	if (!stack_b)
		return (NULL);
	current = stack_b;
	cheapest = current;
	min_cost = ft_calc_cost_b_to_a(stack_a, stack_b, current);
	while (current)
	{
		current_cost = ft_calc_cost_b_to_a(stack_a, stack_b, current);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
