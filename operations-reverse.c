/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:17:27 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/29 22:23:06 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Generic function to reverse rotate any stack (last becomes first).
 *
 * Moves the last element of the stack to the front. The last element becomes
 * the new head. Maintains proper doubly-linked list integrity. Handles edge
 * cases: empty stack, single element, or null pointers.
 *
 * @param stack Pointer to the pointer of the first node in the stack.
 */
static void	reverse_generic(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = ft_last_node(*stack);
	ft_remove_last(stack);
	ft_add_front(stack, temp);
}

/**
 * @brief Reverse rotate stack A (last element becomes first).
 *
 * Shifts all elements of stack A down by one position. The last element
 * becomes the first element. Does nothing if stack has 0 or 1 elements.
 * Prints "rra" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 */
void	ft_rra(t_stack **stack_a)
{
	reverse_generic(stack_a);
	ft_printf("rra\n");
}

/**
 * @brief Reverse rotate stack B (last element becomes first).
 *
 * Shifts all elements of stack B down by one position. The last element
 * becomes the first element. Does nothing if stack has 0 or 1 elements.
 * Prints "rrb" to standard output.
 *
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_rrb(t_stack **stack_b)
{
	reverse_generic(stack_b);
	ft_printf("rrb\n");
}

/**
 * @brief Reverse rotate both stacks simultaneously.
 *
 * Performs rra and rrb operations at the same time. Reverse rotates both
 * stack A and stack B. Does nothing for stacks that have 0 or 1 elements.
 * Prints "rrr" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_generic(stack_a);
	reverse_generic(stack_b);
	ft_printf("rrr\n");
}
