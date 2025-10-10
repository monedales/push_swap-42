/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:40:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 17:52:19 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Perform combined rotations on both stacks simultaneously.
 *
 * Executes `min_cost` combined rotations on stack A and stack B.
 * Rotates upwards (`rr`) if `rotate_up` is 1, or downwards (`rrr`) if 0.
 *
 * @param stack_a Pointer to the head pointer of stack A.
 * @param stack_b Pointer to the head pointer of stack B.
 * @param rotate_up Direction flag: 1 = rotate up (rr), 0 = rotate down (rrr).
 * @param min_cost Number of combined rotations to perform.
 */
void	ft_combined_rotations(t_stack **stack_a, t_stack **stack_b,
			int rotate_up, int min_cost)
{
	int	i;

	i = 0;
	while (i < min_cost)
	{
		if (rotate_up)
			ft_rr(stack_a, stack_b);
		else
			ft_rrr(stack_a, stack_b);
		i++;
	}
}

/**
 * @brief Perform individual rotations on stack A.
 *
 * Rotates stack A `cost_a` times in the direction specified by `rotate_up_a`.
 *
 * @param stack_a Pointer to the head pointer of stack A.
 * @param cost_a Number of rotations to perform.
 * @param rotate_up_a Direction flag: 1 = rotate up (ra), 0 = rotate down (rra).
 */
void	ft_individual_rotations_a(t_stack **stack_a, int cost_a,
			int rotate_up_a)
{
	int	i;

	i = 0;
	while (i < cost_a)
	{
		if (rotate_up_a)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
		i++;
	}
}

/**
 * @brief Perform individual rotations on stack B.
 *
 * Rotates stack B `cost_b` times in the direction specified by `rotate_up_b`.
 *
 * @param stack_b Pointer to the head pointer of stack B.
 * @param cost_b Number of rotations to perform.
 * @param rotate_up_b Direction flag: 1 = rotate up (rb), 0 = rotate down (rrb).
 */
void	ft_individual_rotations_b(t_stack **stack_b, int cost_b,
			int rotate_up_b)
{
	int	i;

	i = 0;
	while (i < cost_b)
	{
		if (rotate_up_b)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
		i++;
	}
}

/**
 * @brief Apply combined rotations and adjust remaining individual costs.
 *
 * Performs combined rotations first to reduce total operations, then updates
 * the remaining rotation costs for stack A and stack B. Remaining rotations
 * should be applied individually after this function.
 *
 * @param stack_a Pointer to the head pointer of stack A.
 * @param stack_b Pointer to the head pointer of stack B.
 * @param costs Array of three integers: [cost_a, cost_b, rotate_up].
 *     - cost_a and cost_b are the remaining rotations for each stack.
 *     - rotate_up indicates direction for combined rotations (1 = up, 0 = down).
 */
void	ft_apply_combined_rotations(t_stack **stack_a, t_stack **stack_b,
			int costs[3])
{
	if (costs[0] < costs[1])
	{
		ft_combined_rotations(stack_a, stack_b, costs[2], costs[0]);
		costs[1] -= costs[0];
		costs[0] = 0;
	}
	else
	{
		ft_combined_rotations(stack_a, stack_b, costs[2], costs[1]);
		costs[0] -= costs[1];
		costs[1] = 0;
	}
}
