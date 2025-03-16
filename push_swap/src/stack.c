/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:51:33 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/15 16:37:03 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int nbr)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->number = nbr;
	new->next = NULL;
	new->target = NULL;
	new->position = -1;
	new->cost = -1;
	return (new);
}

t_stack	*init_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->top = NULL;
	new->max = NULL;
	new->min = NULL;
	new->size = 0;
	return (new);
}

t_node	*get_last_node(t_stack *stack)
{
	t_node	*last;
	
	if (is_stack_empty(stack))
		return (NULL);
	last = stack->top;
	while (last->next)
	last = last->next;
	return (last);
}
