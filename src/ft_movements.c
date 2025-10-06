/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/06 19:32:44 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Rotate stack A to bring target element to top.
 *
 * Uses the most efficient rotation direction to bring the specified
 * element to the top of stack A.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param target Pointer to element to bring to top.
 */
void	ft_rotate_a_to_top(t_stack **stack_a, t_stack *target)
{
	int	cost;
	int	rotate_up;

	cost = ft_efficient_rotation_cost(*stack_a, target);
	rotate_up = ft_should_rotate_up(*stack_a, target);
	while (cost-- > 0)
	{
		if (rotate_up)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
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

	if (!*stack_b)
		return ;
	cost = ft_calc_rb(*stack_b, element);
	rotate_up = ft_should_rotate_up_b(*stack_b, element);
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
 * @brief Execute optimal move from B to A with combined rotations.
 *
 * Calculates rotation costs for both stacks, uses combined operations
 * (rr/rrr) when both rotate in same direction to reduce total operations,
 * then performs remaining individual rotations before pushing from B to A.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param element Pointer to element to move from B to A.
 */
void	ft_best_move_b_to_a(t_stack **stack_a, t_stack **stack_b,
			t_stack *element)
{
	t_stack	*target_a;
	int		costs[3];
	int		rotate_up_b;

	if (!element)
		return ;
	target_a = ft_find_target_in_a(*stack_a, element->index);
	costs[0] = ft_efficient_rotation_cost(*stack_a, target_a);
	costs[1] = ft_efficient_rotation_cost(*stack_b, element);
	costs[2] = ft_should_rotate_up(*stack_a, target_a);
	rotate_up_b = ft_should_rotate_up(*stack_b, element);
	if (costs[2] == rotate_up_b)
		ft_apply_combined_rotations(stack_a, stack_b, costs);
	ft_individual_rotations_a(stack_a, costs[0], costs[2]);
	ft_individual_rotations_b(stack_b, costs[1], rotate_up_b);
	ft_pa(stack_a, stack_b);
}
