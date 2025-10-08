/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:39:50 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/08 18:16:56 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Generic function to push from one stack to another.
 *
 * Takes the top element from the source stack and moves it to the top of the
 * destination stack. Maintains proper doubly-linked list integrity. Handles
 * edge cases: empty source stack or null pointers.
 *
 * @param dst Pointer to the pointer of the destination stack.
 * @param src Pointer to the pointer of the source stack.
 */
void	push_generic(t_stack **dst, t_stack **src)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	temp = ft_remove_first(src);
	ft_add_front(dst, temp);
}

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
