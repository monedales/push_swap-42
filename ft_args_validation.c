/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:12 by mona              #+#    #+#             */
/*   Updated: 2025/09/26 16:39:25 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

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

void	ft_args_validation(int argc, char **argv)
{
	char	**args;
	int		should_free;

	if (argc == 2 && !argv[1][0])
		ft_error();
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
