/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/03 16:46:29 by mona             ###   ########.fr       */
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
	t_stack *current;
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
 * @brief Find target position for element in stack B.
 *
 * Determines where an element should be placed in stack B to maintain
 * descending order. Stack B is kept sorted with largest elements on top.
 *
 * @param stack_b Pointer to the first node of stack B.
 * @param element Pointer to element to place in stack B.
 * @return Position index where element should be inserted.
 */
static int	ft_find_target_pos_b(t_stack *stack_b, t_stack *element)
{
	t_stack	*current;
	int		position;

	if (!stack_b)
		return (0);
	if (element->index > stack_b->index)
		return (0);
	current = stack_b;
	position = 0;
	while (current->next)
	{
		if (element->index < current->index
			&& element->index > current->next->index)
			return (position + 1);
		position++;
		current = current->next;
	}
	return (position + 1);
}

/**
 * @brief Calculate cost to place element in correct position in stack B.
 *
 * Determines the number of operations needed to rotate stack B so that
 * the target position is at the top, ready for insertion.
 *
 * @param stack_b Pointer to the first node of stack B.
 * @param element Pointer to element to place in stack B.
 * @return Cost in operations to prepare position in stack B.
 */
int	ft_calc_rb(t_stack *stack_b, t_stack *element)
{
	int	target_position;
	int	stack_size;
	int	cost_up;
	int	cost_down;

	if (!stack_b)
		return (0);
	target_position = ft_find_target_pos_b(stack_b, element);
	stack_size = ft_list_size(stack_b);
	cost_up = target_position;
	cost_down = stack_size - target_position;
	if (cost_up <= cost_down)
		return (cost_up);
	return (cost_down);
}

/**
 * @brief Calculate total cost to move element from A to B.
 *
 * Combines the cost to bring element to top of A with the cost to
 * place it in the correct position in B.
 *
 * @param stack_a Pointer to the first node of stack A.
 * @param stack_b Pointer to the first node of stack B.
 * @param element Pointer to element to move from A to B.
 * @return Total cost in operations for the complete move.
 */
int	ft_calc_total(t_stack *stack_a, t_stack *stack_b, t_stack *element)
{
	int	cost_a;
	int	cost_b;

	cost_a = ft_calc_ra(stack_a, element);
	cost_b = ft_calc_rb(stack_b, element);
	return (cost_a + cost_b);
}

/**
 * @brief Find the element with the lowest cost to move from A to B.
 *
 * Iterates through all elements in stack A, calculates the total cost
 * for each element using ft_calc_total, and returns the element with
 * the minimum cost. Includes debug output for study purposes.
 *
 * @param stack_a Pointer to the first node of stack A.
 * @param stack_b Pointer to the first node of stack B.
 * @return Pointer to the cheapest element, or NULL if stack A is empty.
 */
t_stack	*ft_cheapest_element(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		current_cost;
	int		min_cost;

	if (!stack_a)
		return (NULL);
	cheapest = stack_a;
	min_cost = ft_calc_total(stack_a, stack_b, stack_a);
	current = stack_a->next;
	while (current)
	{
		current_cost = ft_calc_total(stack_a, stack_b, current);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
