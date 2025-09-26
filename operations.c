/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:01:10 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/26 19:57:28 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("sa");
}

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
	ft_printf("sb");
}
