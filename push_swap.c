/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:33:10 by mona              #+#    #+#             */
/*   Updated: 2025/09/26 15:38:43 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_parse_args(argc, argv);
	if (!stack_a)
		ft_error();
	// check if stack a is already sorted
	stack_b = NULL;
	// Sort both stacks - sort_stacks(&stack_a, &stack_b);
	// Clean up
	free_stack(&stack_a);
	return (0);
}
