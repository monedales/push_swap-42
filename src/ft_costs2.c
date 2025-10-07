/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/07 14:20:34 by maria-ol         ###   ########.fr       */
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
 * @brief Get position of element in stack (0-indexed from head).
 *
 * @param stack Pointer to stack head.
 * @param target Pointer to target element.
 * @return Position of element, or -1 if not found.
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
 * @brief Calculate efficient rotation cost using both directions.
 *
 * @param stack Pointer to stack head.
 * @param target Pointer to target element.
 * @return Minimum cost to bring target to top.
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
 * @brief Check if should rotate up or down efficiently.
 *
 * @param stack Pointer to stack head.
 * @param target Pointer to target element.
 * @return 1 if rotate up is cheaper, 0 if rotate down is cheaper.
 */
int	ft_should_rotate_up(t_stack *stack, t_stack *target)
{
	int	position;
	int	stack_size;

	position = ft_get_position(stack, target);
	if (position == -1)
		return (1);
	stack_size = ft_list_size(stack);
	return (position <= stack_size / 2);
}
