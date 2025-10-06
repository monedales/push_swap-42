/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:39:50 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/03 20:02:23 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Push the first element from stack A to stack B.
 *
 * Takes the top element from stack A and moves it to the top of stack B.
 * The first element of stack A becomes the first element of stack B.
 * Does nothing if stack A is empty. Prints "pb" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = ft_remove_first(stack_a);
	ft_add_front(stack_b, temp);
	ft_printf("pb\n");
}

/**
 * @brief Push the first element from stack B to stack A.
 *
 * Takes the top element from stack B and moves it to the top of stack A.
 * The first element of stack B becomes the first element of stack A.
 * Does nothing if stack B is empty. Prints "pa" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = ft_remove_first(stack_b);
	ft_add_front(stack_a, temp);
	ft_printf("pa\n");
}

/**
 * @brief Perform combined rotations when both stacks rotate same direction.
 *
 * @param stack_a Pointer to stack A pointer.
 * @param stack_b Pointer to stack B pointer.
 * @param rotate_up Direction flag (1 for up, 0 for down).
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
