/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/03 19:34:55 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Rotate stack A to bring target element to top.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param target Pointer to element to bring to top.
 */
void	ft_rotate_a_to_top(t_stack **stack_a, t_stack *target)
{
	int	cost;
	int	rotate_up;

	cost = ft_calc_ra(*stack_a, target);
	rotate_up = ft_should_rotate_up_a(*stack_a, target);
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
 * @brief Execute the best move to transfer element from A to B.
 *
 * Simple version: rotate A to bring target to top, rotate B to correct
 * position, then push from A to B. Clear and straightforward logic.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param target Pointer to element to move from A to B.
 */
void	ft_best_move(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	if (!stack_a || !*stack_a || !target)
		return ;
	ft_rotate_b_to_pos(stack_b, target);
	ft_rotate_a_to_top(stack_a, target);
	ft_pa(stack_a, stack_b);
}
