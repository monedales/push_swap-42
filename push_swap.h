/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:59:41 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/26 16:31:21 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

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

/* parsing & validation */
void	ft_args_validation(int argc, char **argv);
t_stack	*ft_parse_args(int argc, char **argv);

#endif