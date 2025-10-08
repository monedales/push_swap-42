/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:05:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/08 18:45:10 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa_silent(t_stack **stack_a, t_stack **stack_b)
{
	push_generic(stack_a, stack_b);
}

void	ft_pb_silent(t_stack **stack_a, t_stack **stack_b)
{
	push_generic(stack_b, stack_a);
}

void	ft_ra_silent(t_stack **stack_a)
{
	rotate_generic(stack_a);
}

void	ft_rb_silent(t_stack **stack_b)
{
	rotate_generic(stack_b);
}

void	ft_rr_silent(t_stack **stack_a, t_stack **stack_b)
{
	rotate_generic(stack_a);
	rotate_generic(stack_b);
}
