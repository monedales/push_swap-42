/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:09:52 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/16 18:02:24 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_node(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_last_node(t_stack *list)
{
	t_stack	*last;

	last = list;
	while (last->next)
		last = last->next;
	return (last);
}

t_stack	ft_add_last(t_stack **list, t_stack *node)
{
	t_stack	*last;

	if (*list == NULL)
		*list = node;
	else
	{
		last = ft_last_node(*list);
		node->prev = last;
		last->next = node;
	}
	return (*last);
}
