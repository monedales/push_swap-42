/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:02:38 by mona              #+#    #+#             */
/*   Updated: 2025/10/08 20:10:20 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Execute a single stack operation based on instruction string.
 *
 * This function acts as a command dispatcher, it compares the operation string
 * against all push swap operations using ft_strncmp with the exact length.
 *
 * @param stack_a Double pointer to stack A (allows modification of the stack)
 * @param stack_b Double pointer to stack B (allows modification of the stack)
 * @param operation Null-terminated string containing the operation name with
 *                  newline (e.g., "sa\n", "pb\n", "rra\n")
 * @return void (no return value)
 */
static void	ft_execute_operation(t_stack **stack_a, t_stack **stack_b,
				char *operation)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		ft_sa_silent(stack_a);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		ft_sb_silent(stack_b);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ft_ss_silent(stack_a, stack_b);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		ft_pa_silent(stack_a, stack_b);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		ft_pb_silent(stack_a, stack_b);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ft_ra_silent(stack_a);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		ft_rb_silent(stack_b);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		ft_rr_silent(stack_a, stack_b);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		ft_rra_silent(stack_a);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		ft_rrb_silent(stack_b);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		ft_rrr_silent(stack_a, stack_b);
	else
		ft_error();
}

/**
 * @brief Read and execute operations from stdin until EOF.
 *
 * Main operation processing loop for the checker. Reads operations from stdin
 * using get_next_line(), executes each operation silently, and frees memory
 * after each line. Continues until get_next_line() returns NULL (EOF).
 *
 * Memory management: Each get_next_line() allocates memory that must be freed
 * to prevent leaks, especially important when processing many operations.
 *
 * @param stack_a Double pointer to stack A (starts with input, modified by ops)
 * @param stack_b Double pointer to stack B (starts empty, modified by ops)
 *
 * @note Uses get_next_line(0) where 0 is stdin file descriptor
 * @warning Does not validate final state - caller must check if sorted
 * @warning Exits via ft_error() if invalid operation is encountered
 */
void	ft_read_and_execute_operations(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_execute_operation(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}
