/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:18:11 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 22:44:21 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static	t_node	*get_prev_node(t_stack *stack, t_node *last)
{
	t_node	*prev;

	prev = stack->top;
	while (prev)
	{
		if (prev->next == last)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

static	void	reverse_rotate(t_stack *stack, bool *flag)
{
	t_node	*prev;
	t_node	*last;

	if (!is_at_least_two(stack))
		return ;
	last = get_last_node(stack);
	if (!last)
	{
		*flag = false;
		return ;
	}
	prev = get_prev_node(stack, last);
	if (!prev)
	{
		*flag = false;
		return ;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a, bool *flag)
{
	reverse_rotate(a, flag);
	if (!*flag)
		return ;
	write_op("rra");
}

void	rrb(t_stack *b, bool *flag)
{
	reverse_rotate(b, flag);
	if (!*flag)
		return ;
	write_op("rrb");
}

void	rrr(t_stack *a, t_stack *b, bool *flag)
{
	reverse_rotate(a, flag);
	if (!*flag)
		return ;
	reverse_rotate(b, flag);
	if (!*flag)
		return ;
	write_op("rrr");
}
