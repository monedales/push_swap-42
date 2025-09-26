/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:45:00 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/26 17:19:21 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
 * @return Array of string arguments ready for processing.
 */
static char	**ft_get_args_array(int argc, char **argv, int *should_free)
{
	char	**args;

	*should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
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
 */
static t_stack	*ft_create_stack_from_args(char **args, int should_free)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i])
	{
		new_node = ft_create_node(ft_atoi(args[i]));
		if (!new_node)
		{
			free_stack(&stack_a);
			if (should_free)
				ft_free_arr(args, i);
			ft_error();
		}
		ft_add_last(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

/**
 * @brief Main parsing function that creates a stack from command-line arguments.
 *
 * Coordinates the full parsing process: validates arguments, extracts them
 * into the proper format, creates the stack, and handles memory cleanup.
 * This function integrates validation and stack creation into a single
 * interface for the main program.
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return Pointer to the head of the created and validated stack.
 */
t_stack	*ft_parse_args(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	int		should_free;
	int		word_count;

	ft_args_validation(argc, argv);
	args = ft_get_args_array(argc, argv, &should_free);
	stack_a = ft_create_stack_from_args(args, should_free);
	if (should_free)
	{
		word_count = ft_count_words(argv[1], ' ');
		ft_free_arr(args, word_count);
	}
	return (stack_a);
}
