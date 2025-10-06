/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:40:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/06 18:47:48 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Find element with maximum index in stack.
 *
 * @param stack Pointer to stack head.
 * @return Pointer to element with highest index.
 */
t_stack	*ft_find_max_element(t_stack *stack)
{
	t_stack	*current;
	t_stack	*max_element;

	if (!stack)
		return (NULL);
	current = stack;
	max_element = current;
	while (current)
	{
		if (current->index > max_element->index)
			max_element = current;
		current = current->next;
	}
	return (max_element);
}

/**
 * @brief Find element with minimum index in stack.
 *
 * @param stack Pointer to stack head.
 * @return Pointer to element with lowest index.
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

/**
 * @brief Rotate stack B to bring target element to top.
 *
 * Uses the most efficient rotation direction to bring the specified
 * element to the top of stack B.
 *
 * @param stack_b Pointer to stack B pointer.
 * @param target Pointer to target element to bring to top.
 */
void	ft_rotate_b_to_top(t_stack **stack_b, t_stack *target)
{
	int	cost;
	int	rotate_up;

	if (!*stack_b || !target)
		return ;
	cost = ft_efficient_rotation_cost(*stack_b, target);
	rotate_up = ft_should_rotate_up(*stack_b, target);
	while (cost-- > 0)
	{
		if (rotate_up)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
}
