/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:33:10 by mona              #+#    #+#             */
/*   Updated: 2025/09/30 16:21:26 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	int		sort;
	t_stack	*current;

	current = stack;
	sort = 0;
	if (stack == NULL)
		return (sort);
	while (current && current->next)
	{
		if (current->content > current->next->content)
		{
			sort = 0;
			break ;
		}
		current = current->next;
		sort = 1;
	}
	return (sort);
}

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
	if (ft_is_sorted(stack_a) == 1)
		ft_printf("tá certo\n");
	else
	{
		stack_b = NULL;
		print_stack(stack_a);
		ft_sa(&stack_a);
		print_stack(stack_a);
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
		/* rotate operations demonstration */
		ft_pb(&stack_a, &stack_b);  // Move one element to B for rb test
		ft_pb(&stack_a, &stack_b);  // Move another element to B
		print_stack(stack_a);
		print_stack(stack_b);
		ft_ra(&stack_a);
		print_stack(stack_a);
		ft_rb(&stack_b);
		print_stack(stack_b);
		ft_rr(&stack_a, &stack_b);  // Rotate both simultaneously
		print_stack(stack_a);
		print_stack(stack_b);
		/* reverse rotate operations demonstration */
		ft_rra(&stack_a);  // Reverse rotate A
		print_stack(stack_a);
		ft_rrb(&stack_b);  // Reverse rotate B
		print_stack(stack_b);
		ft_rrr(&stack_a, &stack_b);  // Reverse rotate both simultaneously
		print_stack(stack_a);
		print_stack(stack_b);
		// free the stacks at the end
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
