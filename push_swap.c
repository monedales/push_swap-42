/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:33:10 by mona              #+#    #+#             */
/*   Updated: 2025/09/29 21:51:41 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Main entry point for the push_swap sorting algorithm.
 *
 * Parses and validates command-line arguments, creates the initial stack A,
 * and prepares for the sorting algorithm implementation. Currently handles
 * argument processing and memory management setup. Future implementation
 * will include sorting algorithm and stack operations.
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line argument strings containing integers.
 * @return 0 on successful execution, exits with error code on failure.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_parse_args(argc, argv);
	if (!stack_a)
		ft_error();
	print_stack(stack_a);
	ft_sa(&stack_a);
	print_stack(stack_a);
	stack_b = NULL;
	ft_pb(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_pb(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_pb(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_sb(&stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	/* push back from B to A */
	ft_pa(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_pa(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_pa(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
