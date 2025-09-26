/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:01:10 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/26 20:33:56 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (temp->next)
		temp->next->prev = temp;
	(*stack_a)->prev = NULL;
	temp->prev = *stack_a;
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
	t_stack	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (temp->next)
		temp->next->prev = temp;
	(*stack_b)->prev = NULL;
	temp->prev = *stack_b;
	ft_printf("sb\n");
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
