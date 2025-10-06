/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/03 21:36:24 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Calculate total cost to move element from A to B.
 *
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param element Element to move.
 * @return Total cost in operations.
 */
int	ft_calc_total(t_stack *stack_a, t_stack *stack_b, t_stack *element)
{
	int	ra_cost;
	int	rb_cost;

	ra_cost = ft_calc_ra(stack_a, element);
	rb_cost = ft_calc_rb(stack_b, element);
	return (ra_cost + rb_cost);
}

/**
 * @brief Find target position in A for element from B.
 *
 * @param stack_a Stack A.
 * @param element Element to insert.
 * @return Position where element should be inserted.
 */
static int	ft_find_target_pos_a(t_stack *stack_a, t_stack *element)
{
	t_stack	*current;
	t_stack	*best_match;
	int		pos;
	int		best_pos;

	if (!stack_a || !element)
		return (0);
	current = stack_a;
	best_match = NULL;
	pos = 0;
	best_pos = 0;
	while (current)
	{
		if (current->index > element->index
			&& (!best_match || current->index < best_match->index))
		{
			best_match = current;
			best_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (best_pos);
}

/**
 * @brief Calculate cost to position element in A when pushing from B.
 *
 * @param stack_a Stack A.
 * @param element Element from B to position.
 * @return Cost in operations.
 */
int	ft_calc_ra_for_b(t_stack *stack_a, t_stack *element)
{
	int	target_pos;
	int	stack_size;

	target_pos = ft_find_target_pos_a(stack_a, element);
	stack_size = ft_list_size(stack_a);
	if (target_pos <= stack_size / 2)
		return (target_pos);
	else
		return (stack_size - target_pos);
}

/**
 * @brief Find cheapest element to move from A to B.
 *
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @return Pointer to cheapest element.
 */
t_stack	*ft_cheapest_element(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_cost;
	int		current_cost;

	if (!stack_a)
		return (NULL);
	current = stack_a;
	cheapest = current;
	min_cost = ft_calc_total(stack_a, stack_b, current);
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
