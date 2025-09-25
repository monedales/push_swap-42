/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mona <mona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:59:41 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/24 19:30:53 by mona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_create_node(int content);
t_stack	*ft_last_node(t_stack *head);
t_stack	*ft_add_last(t_stack **head, t_stack *node);
t_stack	*ft_add_front(t_stack **head, t_stack *node);
ssize_t	ft_list_size(t_stack *head);
void 	print_stack(t_stack *head);
t_stack *ft_remove_first(t_stack **head);
t_stack *ft_remove_last(t_stack **head);

#endif