/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:55:40 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 00:23:42 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!is_at_least_two(stack))
		return ;
	last = get_last_node(stack);
	if (!last)
		return ;
	prev = get_prev_node(stack, last);
	if (!prev)
		return ;
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write_op("rra");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write_op("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write_op("rrr");
}
