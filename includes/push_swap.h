/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:59:41 by maria-ol          #+#    #+#             */
/*   Updated: 2025/10/06 19:50:11 by maria-ol         ###   ########.fr       */
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
int		ft_get_position(t_stack *stack, t_stack *target);
int		ft_efficient_rotation_cost(t_stack *stack, t_stack *target);
int		ft_should_rotate_up(t_stack *stack, t_stack *target);
t_stack	*ft_get_element_at_position(t_stack *stack, int position);
t_stack	*ft_find_element_by_content(t_stack *stack, int content);
t_stack	*ft_get_from_end(t_stack *stack, int pos_from_end);
t_stack	*ft_find_max_element(t_stack *stack);
t_stack	*ft_find_min_element(t_stack *stack);
void	ft_rotate_b_to_top(t_stack **stack_b, t_stack *target);

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
int		ft_calc_ra_for_b(t_stack *stack_a, t_stack *element);
int		ft_calc_total(t_stack *stack_a, t_stack *stack_b, t_stack *element);
int		ft_should_rotate_up_a(t_stack *stack_a, t_stack *target);
int		ft_should_rotate_up_b(t_stack *stack_b, t_stack *element);
t_stack	*ft_cheapest_element(t_stack *stack_a, t_stack *stack_b);
t_stack	*ft_find_target_in_a(t_stack *stack_a, int value);
int		ft_calc_cost_b_to_a(t_stack *stack_a, t_stack *stack_b,
			t_stack *element);
t_stack	*ft_cheapest_b_to_a(t_stack *stack_a, t_stack *stack_b);

/* turk algorithm movements */
void	ft_best_move(t_stack **stack_a, t_stack **stack_b, t_stack *target);
void	ft_turk_algorithm(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a_to_top(t_stack **stack_a, t_stack *target);
void	ft_rotate_b_to_pos(t_stack **stack_b, t_stack *element);
void	ft_best_move_b_to_a(t_stack **stack_a, t_stack **stack_b,
			t_stack *element);

/* chunk algorithm */
int		ft_get_chunk_size(int stack_size);
int		ft_in_chunk(t_stack *element, int chunk_min, int chunk_max);
t_stack	*ft_find_chunk_element(t_stack *stack_a, int chunk_min, int chunk_max);

/* operations - swap */
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

/* operations - push */
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_combined_rotations(t_stack **stack_a, t_stack **stack_b,
			int rotate_up, int min_cost);
void	ft_individual_rotations_a(t_stack **stack_a, int cost_a,
			int rotate_up_a);
void	ft_individual_rotations_b(t_stack **stack_b, int cost_b,
			int rotate_up_b);
void	ft_apply_combined_rotations(t_stack **stack_a, t_stack **stack_b,
			int costs[3]);

/* operations - rotate */
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

/* operations - reverse rotate */
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif