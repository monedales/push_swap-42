/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:45:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/10 16:27:37 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Assigns index values representing sorted positions to stack elements.
 *
 * Iterates through the stack and assigns to every node an `index` corresponding 
 * to its position in the sorted order. The smallest element receives index `0`,
 * the next smallest `1`, and so on.
 *
 * @param stack Pointer to the pointer of the first node in the stack.
 * 
 */
static void	ft_assign_index(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->content < current->content)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

/**
 * @brief Extracts arguments array from command-line parameters.
 *
 * Determines the input format (single quoted string vs multiple arguments)
 * and returns the appropriate arguments array. Sets should_free flag to
 * indicate if the returned array needs to be freed later.
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @param should_free Pointer to flag indicating if array should be freed.
 * @return A NULL-terminated array of numeric strings.
 */
static char	**ft_get_args_array(int argc, char **argv, int *should_free)
{
	char	**args;

	*should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			ft_error();
		*should_free = 1;
	}
	else
		args = argv + 1;
	return (args);
}

/**
 * @brief Creates a stack from an array of string arguments.
 *
 * Converts string arguments to integers and creates t_stack nodes for each
 * number, linking them into a doubly-linked list. Handles memory allocation
 * errors by cleaning up partial stack and calling ft_error() on failure.
 *
 * @param args Array of string arguments representing numbers.
 * @param should_free Flag indicating if args array should be freed on error.
 * @return Pointer to the head of the created stack.
 * 
 * @see See also: ft_create_node(), ft_add_last(), ft_free_arr(), ft_error()
 */
static t_stack	*ft_create_stack_from_args(char **args, int should_free)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	int		idx;

	stack_a = NULL;
	idx = 0;
	while (args[idx])
	{
		new_node = ft_create_node(ft_atoi(args[idx]));
		if (!new_node)
		{
			free_stack(&stack_a);
			if (should_free)
				ft_free_arr(args, idx);
			ft_error();
		}
		ft_add_last(&stack_a, new_node);
		idx++;
	}
	return (stack_a);
}

/**
 * @brief Main parsing function that creates a stack from command-line arguments.
 *
 * Orchestrates the entire argument handling process:
 *  - Validates syntax and content of the arguments (`ft_args_validation()`).
 *  - Extracts the usable array of numbers (`ft_get_args_array()`).
 *  - Converts arguments to integers and builds the initial stack 
 * (`ft_create_stack_from_args()`).
 *  - Assigns indices based on sorted order (`ft_assign_index()`).
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return Pointer to the head of the created and validated stack.
 * 
 * @see See also: ft_args_validation(), ft_assign_index()
 */
t_stack	*ft_parse_args(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	int		should_free;
	int		word_count;

	ft_args_validation(argc, argv);
	should_free = 0;
	args = ft_get_args_array(argc, argv, &should_free);
	stack_a = ft_create_stack_from_args(args, should_free);
	if (should_free)
	{
		word_count = ft_count_words(argv[1], ' ');
		ft_free_arr(args, word_count);
	}
	ft_assign_index(&stack_a);
	return (stack_a);
}
