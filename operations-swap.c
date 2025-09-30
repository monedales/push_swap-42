/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:01:10 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/29 21:40:22 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Generic function to swap the first two elements of any stack.
 *
 * Swaps the first two nodes in a doubly-linked stack, maintaining proper
 * forward and backward linkage. Handles edge cases: empty stack, single
 * element, or null pointers. Used by sa, sb, and ss operations.
 *
 * @param stack Pointer to the pointer of the first node in the stack.
 */
static void	swap_generic(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (temp->next)
		temp->next->prev = temp;
	(*stack)->prev = NULL;
	temp->prev = *stack;
}

/**
 * @brief Swap the first 2 elements at the top of stack A.
 *
 * Stack operation to swap the first two nodes of stack A. The first element
 * becomes the second, and the second element becomes the first. Does nothing
 * if there is only one or no elements. Prints "sa" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 */
void	ft_sa(t_stack **stack_a)
{
	swap_generic(stack_a);
	ft_printf("sa\n");
}

/**
 * @brief Swap the first 2 elements at the top of stack B.
 *
 * Stack operation to swap the first two nodes of stack B. The first element
 * becomes the second, and the second element becomes the first. Does nothing
 * if there is only one or no elements. Prints "sb" to standard output.
 *
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_sb(t_stack **stack_b)
{
	swap_generic(stack_b);
	ft_printf("sb\n");
}

/**
 * @brief Swap the first 2 elements at the top of both stacks simultaneously.
 *
 * Performs sa and sb operations at the same time. Swaps the first two nodes
 * of both stack A and stack B simultaneously. Does nothing for stacks that
 * have only one or no elements. Prints "ss" to standard output.
 *
 * @param stack_a Pointer to the pointer of the first node in stack A.
 * @param stack_b Pointer to the pointer of the first node in stack B.
 */
void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_generic(stack_a);
	swap_generic(stack_b);
	ft_printf("ss\n");
}
