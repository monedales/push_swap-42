/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_UNUSED.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 22:05:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/07 14:20:47 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/**
 * @brief Rotate stack B to correct position for insertion.
 *
 * @param stack_b Pointer to stack B pointer.
 * @param element Pointer to element to be inserted.
 */
void	ft_rotate_b_to_pos(t_stack **stack_b, t_stack *element)
{
	int	cost;
	int	rotate_up;
	int	i;

	if (!*stack_b)
		return ;
	cost = ft_calc_rb(*stack_b, element);
	rotate_up = ft_should_rotate_up_b(*stack_b, element);
	i = 0;
	while (i < cost)
	{
		if (rotate_up)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
		i++;
	}
}