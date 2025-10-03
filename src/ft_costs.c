/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/03 18:21:04 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Check if element should rotate up (ra) or down (rra) in stack A.
 *
 * @param stack_a Pointer to the first node of stack A.
 * @param target Pointer to the target element.
 * @return 1 if should rotate up (ra), 0 if should rotate down (rra).
 */
int	ft_should_rotate_up_a(t_stack *stack_a, t_stack *target)
{
	t_stack	*current;
	int		position;
	int		stack_size;

	if (!stack_a || !target)
		return (1);
	position = 0;
	current = stack_a;
	while (current && current != target)
	{
		position++;
		current = current->next;
	}
	stack_size = ft_list_size(stack_a);
	return (position <= stack_size / 2);
}

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
 * @brief Check if should rotate up (rb) or down (rrb) for stack B positioning.
 *
 * @param stack_b Pointer to the first node of stack B.
 * @param element Pointer to element to place in stack B.
 * @return 1 if should rotate up (rb), 0 if should rotate down (rrb).
 */
int	ft_should_rotate_up_b(t_stack *stack_b, t_stack *element)
{
	int	target_position;
	int	stack_size;

	if (!stack_b)
		return (1);
	target_position = ft_find_target_pos_b(stack_b, element);
	stack_size = ft_list_size(stack_b);
	return (target_position <= stack_size / 2);
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
