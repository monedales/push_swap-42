/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:05:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/03 21:36:24 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/**
 * @brief Find element at specific position from head (0-indexed).
 *
 * @param stack Pointer to stack head.
 * @param position Position to find (0 = head).
 * @return Pointer to element at position, or NULL if position invalid.
 */
t_stack	*ft_get_element_at_position(t_stack *stack, int position)
{
	t_stack	*current;
	int		i;

	if (!stack || position < 0)
		return (NULL);
	current = stack;
	i = 0;
	while (current && i < position)
	{
		current = current->next;
		i++;
	}
	return (current);
}

/**
 * @brief Find element with specific content value.
 *
 * @param stack Pointer to stack head.
 * @param content Value to search for.
 * @return Pointer to element with matching content, or NULL if not found.
 */
t_stack	*ft_find_element_by_content(t_stack *stack, int content)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->content == content)
			return (current);
		current = current->next;
	}
	return (NULL);
}
