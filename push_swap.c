/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:33:10 by mona              #+#    #+#             */
/*   Updated: 2025/09/24 20:15:54 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    **get_all_numbers(int argc, char **argv)
{
    char **result;
    char **split;
    int total_numbers;
    int count;
    
    count = 1;
    total_numbers = 0;
    while (count < argc)
    {
        if (ft_strchr(argv[count], " "))
            // split = ft_split(argv[count], " ");
            total_numbers = total_numbers + count_words(argv[count], " ");
        else
            total_numbers++;
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);
    stack_a = //need to parse and validade all the inputs
    if (!stack_a)
        return (ft_error());
    // check if stack a is already sorted
    stack_b = NULL;
    // Sort both stacks 
    // sort_stacks(&stack_a, &stack_b);
    
    // Clean up
    // free_stack(&stack_a);
    return (0);
}