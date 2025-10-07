/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack_UNUSED.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:40:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/07 14:13:07 by maria-ol         ###   ########.fr       */
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
