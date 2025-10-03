/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:00:00 by mona              #+#    #+#             */
/*   Updated: 2025/10/03 16:27:40 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Prints both stacks side by side for visualization.
 */
void	print_both_stacks(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	t_stack	*a_temp;
	t_stack	*b_temp;
	int		max_height;
	int		a_height;
	int		b_height;
	int		i;

	a_height = ft_list_size(stack_a);
	b_height = ft_list_size(stack_b);
	max_height = (a_height > b_height) ? a_height : b_height;
	
	if (operation)
		ft_printf("\n🔄 Operation: %s\n", operation);
	ft_printf("┌─────────┬─────────┐\n");
	ft_printf("│ Stack A │ Stack B │\n");
	ft_printf("├─────────┼─────────┤\n");
	
	a_temp = stack_a;
	b_temp = stack_b;
	
	for (i = 0; i < max_height; i++)
	{
		ft_printf("│");
		if (a_temp)
		{
			ft_printf("   %d    ", a_temp->content);
			a_temp = a_temp->next;
		}
		else
			ft_printf("         ");
		
		ft_printf("│");
		if (b_temp)
		{
			ft_printf("   %d    ", b_temp->content);
			b_temp = b_temp->next;
		}
		else
			ft_printf("         ");
		ft_printf("│\n");
	}
	ft_printf("└─────────┴─────────┘\n");
}

/**
 * @brief Debug version of ft_sort_small with visualization.
 */
void	ft_sort_small_debug(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_list_size(*stack_a);
	ft_printf("🎯 Starting sort for %d elements\n", stack_size);
	print_both_stacks(*stack_a, *stack_b, "INITIAL STATE");
	
	while (stack_size > 3)
	{
		ft_printf("\n📍 Finding minimum in stack of size %d...\n", stack_size);
		ft_move_min_to_top(stack_a, stack_size);
		print_both_stacks(*stack_a, *stack_b, "After moving min to top");
		
		ft_printf("📤 Pushing minimum to stack B...\n");
		ft_pb(stack_a, stack_b);
		print_both_stacks(*stack_a, *stack_b, "pb");
		stack_size--;
	}
	
	ft_printf("\n🔧 Sorting remaining %d elements in stack A...\n", stack_size);
	if (stack_size == 2)
	{
		ft_printf("💫 Using 2-element sort...\n");
		ft_sort_two(stack_a);
	}
	else if (stack_size == 3)
	{
		ft_printf("💫 Using 3-element sort...\n");
		ft_sort_three(stack_a);
	}
	print_both_stacks(*stack_a, *stack_b, "After sorting remaining in A");
	
	ft_printf("\n📥 Pushing elements back from B to A...\n");
	while (*stack_b)
	{
		ft_pa(stack_a, stack_b);
		print_both_stacks(*stack_a, *stack_b, "pa");
	}
	
	ft_printf("\n🎉 SORTING COMPLETE!\n");
	print_both_stacks(*stack_a, *stack_b, "FINAL STATE");
}

/**
 * @brief Debug version of ft_sort_three with step explanations.
 */
void	ft_sort_three_debug(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	
	ft_printf("🎯 Sorting 3 elements: [%d, %d, %d]\n", first, second, third);
	
	if (first > second && second < third && first < third)
	{
		ft_printf("💡 Case: [%d, %d, %d] → swap first two\n", first, second, third);
		ft_sa(stack_a);
	}
	else if (first > second && second > third)
	{
		ft_printf("💡 Case: [%d, %d, %d] → swap + reverse rotate\n", first, second, third);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (first > second && second < third && first > third)
	{
		ft_printf("💡 Case: [%d, %d, %d] → rotate up\n", first, second, third);
		ft_ra(stack_a);
	}
	else if (first < second && second > third && first < third)
	{
		ft_printf("💡 Case: [%d, %d, %d] → swap + rotate up\n", first, second, third);
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (first < second && second > third && first > third)
	{
		ft_printf("💡 Case: [%d, %d, %d] → reverse rotate\n", first, second, third);
		ft_rra(stack_a);
	}
	else
		ft_printf("💡 Already sorted: [%d, %d, %d]\n", first, second, third);
}

/**
 * @brief Debug version of main sorting function.
 */
void	ft_push_swap_debug(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	if (!stack_a || !*stack_a)
	{
		ft_printf("❌ Empty or null stack!\n");
		return ;
	}
	
	if (ft_is_sorted(*stack_a))
	{
		ft_printf("✅ Stack is already sorted!\n");
		print_both_stacks(*stack_a, *stack_b, "Already sorted");
		return ;
	}
	
	stack_size = ft_list_size(*stack_a);
	ft_printf("🚀 PUSH_SWAP DEBUG MODE\n");
	ft_printf("📊 Stack size: %d elements\n", stack_size);
	
	if (stack_size == 2)
	{
		ft_printf("🎯 Using 2-element algorithm\n");
		print_both_stacks(*stack_a, *stack_b, "Initial");
		ft_sort_two(stack_a);
		print_both_stacks(*stack_a, *stack_b, "Final");
	}
	else if (stack_size == 3)
	{
		ft_printf("🎯 Using 3-element algorithm\n");
		print_both_stacks(*stack_a, *stack_b, "Initial");
		ft_sort_three_debug(stack_a);
		print_both_stacks(*stack_a, *stack_b, "Final");
	}
	else if (stack_size <= 5)
	{
		ft_printf("🎯 Using small-number algorithm (4-5 elements)\n");
		ft_sort_small_debug(stack_a, stack_b);
	}
	else
	{
		ft_printf("🎯 Large numbers (%d elements) - not implemented yet\n", stack_size);
		ft_printf("Large stack sorting not yet implemented\n");
	}
}

/**
 * @brief Main function for debug version.
 */
/**
 * @brief Test cost calculation functions with current stacks.
 */
void	ft_test_cost_functions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		position;
	int		ra_cost;
	int		rb_cost;
	int		total_cost;

	ft_printf("\n=== COST FUNCTION TESTING ===\n");
	ft_printf("Stack A size: %d\n", (int)ft_list_size(*stack_a));
	ft_printf("Stack B size: %d\n", (int)ft_list_size(*stack_b));
	current = *stack_a;
	position = 0;
	
	while (current)
	{
		ra_cost = ft_calc_ra(*stack_a, current);
		rb_cost = ft_calc_rb(*stack_b, current);
		total_cost = ft_calc_total(*stack_a, *stack_b, current);
		
		ft_printf("Element %d (pos %d, idx %d): ra_cost=%d, rb_cost=%d, total=%d\n",
			current->content, position, current->index, ra_cost, rb_cost, total_cost);
		
		current = current->next;
		position++;
	}
	ft_printf("=== END COST TESTING ===\n\n");
}

/**
 * @brief Main debug entry point.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		ft_printf("Usage: %s <numbers>\n", argv[0]);
		ft_printf("Example: %s 3 2 1 5 4\n", argv[0]);
		return (0);
	}
	
	ft_printf("🔍 PARSING INPUT...\n");
	stack_a = ft_parse_args(argc, argv);
	if (!stack_a)
		ft_error();
	
	ft_printf("✅ INPUT PARSED SUCCESSFULLY\n");
	stack_b = NULL;
	
	ft_test_cost_functions(&stack_a, &stack_b);
	ft_push_swap_debug(&stack_a, &stack_b);
	
	ft_printf("\n🧹 CLEANUP...\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	ft_printf("✅ PROGRAM COMPLETE\n");
	return (0);
}
