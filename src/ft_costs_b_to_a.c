/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs_b_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/06 17:15:51 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/**
 * @brief Calculate total cost to move element from B to A.
 *
 * Calculates the cost to bring the element to the top of B and
 * prepare the correct insertion position in A.
 *
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param element Element in B to move.
 * @return Total cost in operations.
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
 * @brief Find cheapest element to move from B to A.
 *
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @return Pointer to cheapest element in B.
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
