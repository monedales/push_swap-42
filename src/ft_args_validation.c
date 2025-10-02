/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:12 by mona              #+#    #+#             */
/*   Updated: 2025/09/29 20:31:32 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Checks if the arguments array contains duplicate numbers.
 *
 * Iterates through the arguments array comparing each number with all 
 * subsequent numbers to detect duplicates. Uses ft_atoi() to convert 
 * strings to integers for comparison.
 *
 * @param args Array of string arguments representing numbers.
 * @return 1 if duplicates are found, 0 if all numbers are unique.
 */
static int	ft_is_doppel(char **args)
{
	int	idx;
	int	count;

	idx = 0;
	while (args[idx])
	{
		count = idx + 1;
		while (args[count])
		{
			if (ft_atoi(args[count]) == ft_atoi(args[idx]))
				return (1);
			count++;
		}
		idx++;
	}
	return (0);
}

/**
 * @brief Validates if a string represents a valid integer within range.
 *
 * Checks if the string contains only digits (with optional leading sign)
 * and represents a number within INT_MIN and INT_MAX range. Uses ft_atol()
 * for overflow detection to ensure the number fits in an integer.
 *
 * @param str The string to validate as a number.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
static int	ft_is_valid_number(char *str)
{
	int		idx;
	long	num;

	idx = 0;
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	if (!str[idx])
		return (0);
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	num = ft_atol(str);
	if (num > MAX_INT || num < MIN_INT)
		return (0);
	return (1);
}

/**
 * @brief Validates all arguments in the array and handles cleanup on errors.
 *
 * Iterates through the arguments array, validating each number and checking
 * for duplicates. If validation fails, properly cleans up allocated memory
 * (if should_free is true) and calls ft_error() to terminate the program.
 *
 * @param args Array of string arguments to validate.
 * @param should_free Flag indicating if args array should be freed on error.
 */
static void	ft_validate_args_array(char **args, int should_free)
{
	int	idx;

	idx = 0;
	while (args[idx])
	{
		if (!ft_is_valid_number(args[idx]))
		{
			if (should_free)
				ft_free_arr(args, idx + 1);
			ft_error();
		}
		idx++;
	}
	if (ft_is_doppel(args))
	{
		if (should_free)
			ft_free_arr(args, idx);
		ft_error();
	}
}

/**
 * @brief Checks for mixed argument formats and rejects them.
 *
 * Detects if arguments contain both quoted strings with spaces and individual
 * arguments, which is not a standard push_swap format. If mixed formats are
 * found, calls ft_error() to terminate the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line argument strings.
 */
static void	ft_check_mixed_format(int argc, char **argv)
{
	int	idx;
	int	has_spaces;
	int	has_single_args;

	has_spaces = 0;
	has_single_args = 0;
	idx = 1;
	while (idx < argc)
	{
		if (ft_strchr(argv[idx], ' '))
			has_spaces = 1;
		else
			has_single_args = 1;
		idx++;
	}
	if (has_spaces && has_single_args)
		ft_error();
}

/**
 * @brief Main validation function for command-line arguments.
 *
 * Validates push_swap arguments in both formats: single quoted string
 * ("1 2 3 4") or multiple arguments (1 2 3 4). Rejects mixed formats
 * and performs comprehensive validation including duplicate detection,
 * integer range checking, and numeric format verification.
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line argument strings.
 */
void	ft_args_validation(int argc, char **argv)
{
	char	**args;
	int		should_free;

	if (argc == 2 && !argv[1][0])
		ft_error();
	if (argc > 2)
		ft_check_mixed_format(argc, argv);
	should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error();
		should_free = 1;
	}
	else
		args = argv + 1;
	ft_validate_args_array(args, should_free);
	if (should_free)
		ft_free_arr(args, ft_count_words(argv[1], ' '));
}
