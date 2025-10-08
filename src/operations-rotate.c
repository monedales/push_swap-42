/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:57:58 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/08 18:17:05 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Generic function to rotate any stack forward (first becomes last).
 *
 * Moves the first element of the stack to the end. The second element becomes
 * the new head. Maintains proper doubly-linked list integrity. Handles edge
 * cases: empty stack, single element, or null pointers.
 *
 * @param stack Pointer to the pointer of the first node in the stack.
 */
void	rotate_generic(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	ft_remove_first(stack);
	ft_add_last(stack, temp);
}

/**
 * @brief Rotate stack A forward (first element becomes last).
 *
 * Shifts all elements of stack A up by one position. The first element
 * becomes the last element. Does nothing if stack has 0 or 1 elements.
 * Prints "ra" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 */
void	ft_ra(t_stack **stack_a)
{
	rotate_generic(stack_a);
	ft_printf("ra\n");
}

/**
 * @brief Rotate stack B forward (first element becomes last).
 *
 * Shifts all elements of stack B up by one position. The first element
 * becomes the last element. Does nothing if stack has 0 or 1 elements.
 * Prints "rb" to standard output.
 *
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_rb(t_stack **stack_b)
{
	rotate_generic(stack_b);
	ft_printf("rb\n");
}

/**
 * @brief Rotate both stacks forward simultaneously.
 *
 * Performs ra and rb operations at the same time. Rotates both stack A
 * and stack B forward. Does nothing for stacks that have 0 or 1 elements.
 * Prints "rr" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_generic(stack_a);
	rotate_generic(stack_b);
	ft_printf("rr\n");
}
