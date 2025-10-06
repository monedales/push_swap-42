/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:40:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/06 19:40:00 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Perform combined rotations using rr or rrr.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param rotate_up Direction flag (1 for rr, 0 for rrr).
 * @param min_cost Number of combined rotations to perform.
 */
void	ft_combined_rotations(t_stack **stack_a, t_stack **stack_b,
			int rotate_up, int min_cost)
{
	while (min_cost-- > 0)
	{
		if (rotate_up)
			ft_rr(stack_a, stack_b);
		else
			ft_rrr(stack_a, stack_b);
	}
}

/**
 * @brief Perform individual rotations for stack A.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param cost_a Remaining rotations needed for stack A.
 * @param rotate_up_a Direction flag for stack A rotations.
 */
void	ft_individual_rotations_a(t_stack **stack_a, int cost_a,
			int rotate_up_a)
{
	while (cost_a-- > 0)
	{
		if (rotate_up_a)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

/**
 * @brief Perform individual rotations for stack B.
 *
 * @param stack_b Pointer to stack B pointer.
 * @param cost_b Remaining rotations needed for stack B.
 * @param rotate_up_b Direction flag for stack B rotations.
 */
void	ft_individual_rotations_b(t_stack **stack_b, int cost_b,
			int rotate_up_b)
{
	while (cost_b-- > 0)
	{
		if (rotate_up_b)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
}

/**
 * @brief Apply combined rotations and update costs.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param costs Array [cost_a, cost_b, rotate_up].
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
