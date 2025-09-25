/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:48:12 by mona              #+#    #+#             */
/*   Updated: 2025/09/25 18:23:09 by maria-ol         ###   ########.fr       */
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

void	ft_args_validation(int argc, char **argv)
{
	int		count;
	char	**args;

	if (argc == 2 && !argv[1][0])
		ft_error();
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (ft_is_doppel(args))
		ft_free_arr(args, argv[args])
	
}

// char    **get_all_numbers(int argc, char **argv)
// {
//     char **result;
//     char **split;
//     int total_numbers;
//     int count;
	
//     count = 1;
//     total_numbers = 0;
//     while (count < argc)
//     {
//         if (ft_strchr(argv[count], " "))
//             // split = ft_split(argv[count], " ");
//             total_numbers = total_numbers + count_words(argv[count], " ");
//         else
//             total_numbers++;
		
//         count++;
//     }
// }