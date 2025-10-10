/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack_UNUSED.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:40:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 18:11:58 by maria-ol         ###   ########.fr       */
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

/**
 * @brief Perform optimized rotations using combined operations when possible.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param target Pointer to element to move from A to B.
 */
static void	ft_optimized_rotations(t_stack **stack_a, t_stack **stack_b,
				t_stack *target)
{
	int	cost_a;
	int	cost_b;
	int	rotate_up_a;
	int	rotate_up_b;
	int	min_cost;

	cost_a = ft_calc_ra(*stack_a, target);
	cost_b = ft_calc_rb(*stack_b, target);
	rotate_up_a = ft_should_rotate_up_a(*stack_a, target);
	rotate_up_b = ft_should_rotate_up_b(*stack_b, target);
	if (rotate_up_a == rotate_up_b)
	{
		if (cost_a < cost_b)
			min_cost = cost_a;
		else
			min_cost = cost_b;
		ft_combined_rotations(stack_a, stack_b, rotate_up_a, min_cost);
		cost_a -= min_cost;
		cost_b -= min_cost;
	}
	ft_individual_rotations_a(stack_a, cost_a, rotate_up_a);
	ft_individual_rotations_b(stack_b, cost_b, rotate_up_b);
}

/**
 * @brief Execute the best move to transfer element from A to B.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param target Pointer to element to move from A to B.
 */
void	ft_best_move(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	if (!stack_a || !*stack_a || !target)
		return ;
	ft_optimized_rotations(stack_a, stack_b, target);
	ft_pa(stack_a, stack_b);
}
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