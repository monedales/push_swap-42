/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:02:46 by mona              #+#    #+#             */
/*   Updated: 2025/10/08 20:16:54 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Check if stack A is sorted and stack B is empty.
 *
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 * @return 1 if correctly sorted, 0 otherwise.
 */
static int	ft_is_checker_success(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b != NULL)
		return (0);
	return (ft_is_sorted(stack_a));
}

/**
 * @brief Main checker program.
 *
 * Reads operations from stdin and validates if they correctly sort the stack.
 *
 * @param argc Argument count.
 * @param argv Argument values.
 * @return 0 on success, 1 on error.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_parse_args(argc, argv);
	stack_b = NULL;
	ft_read_and_execute_operations(&stack_a, &stack_b);
	if (ft_is_checker_success(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
