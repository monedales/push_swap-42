/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:02:42 by mona              #+#    #+#             */
/*   Updated: 2025/10/08 18:46:28 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa_silent(t_stack **stack_a)
{
	swap_generic(stack_a);
}

void	ft_sb_silent(t_stack **stack_b)
{
	swap_generic(stack_b);
}

void	ft_ss_silent(t_stack **stack_a, t_stack **stack_b)
{
	swap_generic(stack_a);
	swap_generic(stack_b);
}
