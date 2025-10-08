/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:05:05 by mona              #+#    #+#             */
/*   Updated: 2025/10/08 18:47:15 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra_silent(t_stack **stack_a)
{
	reverse_generic(stack_a);
}

void	ft_rrb_silent(t_stack **stack_b)
{
	reverse_generic(stack_b);
}

void	ft_rrr_silent(t_stack **stack_a, t_stack **stack_b)
{
	reverse_generic(stack_a);
	reverse_generic(stack_b);
}
