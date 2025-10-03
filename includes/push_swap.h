/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:59:41 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/03 16:26:45 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647 
# define MIN_INT -2147483648

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* doubly linked list utils */
t_stack	*ft_create_node(int content);
t_stack	*ft_last_node(t_stack *head);
t_stack	*ft_add_last(t_stack **head, t_stack *node);
t_stack	*ft_add_front(t_stack **head, t_stack *node);
ssize_t	ft_list_size(t_stack *head);
void	print_stack(t_stack *head);
t_stack	*ft_remove_first(t_stack **head);
t_stack	*ft_remove_last(t_stack **head);
void	free_stack(t_stack **stack);
int		ft_find_min_position(t_stack *stack);

/* parsing & validation */
void	ft_args_validation(int argc, char **argv);
t_stack	*ft_parse_args(int argc, char **argv);
int		ft_is_sorted(t_stack *stack);

/* sorting algorithms */
void	ft_sort_two(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort_small(t_stack **stack_a, t_stack **stack_b);
void	ft_push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_move_min_to_top(t_stack **stack_a, int stack_size);

/* cost calculation */
int		ft_calc_ra(t_stack *stack_a, t_stack *target);
int		ft_calc_rb(t_stack *stack_b, t_stack *element);
int		ft_calc_total(t_stack *stack_a, t_stack *stack_b, t_stack *element);

/* operations - swap */
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

/* operations - push */
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);

/* operations - rotate */
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

/* operations - reverse rotate */
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

/* debug functions */
void	print_both_stacks(t_stack *stack_a, t_stack *stack_b, char *operation);
void	ft_sort_small_debug(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three_debug(t_stack **stack_a);
void	ft_push_swap_debug(t_stack **stack_a, t_stack **stack_b);

#endif