/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:57:58 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/29 22:10:19 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_generics(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	ft_remove_first(stack);
	ft_add_last(stack, temp);
}

void	ft_ra(t_stack **stack_a)
{
	rotate_generics(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	rotate_generics(stack_b);
	ft_printf("ra\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_generics(stack_a);
	rotate_generics(stack_b);
	ft_printf("rr\n");
}
