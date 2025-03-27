/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:55:14 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 00:21:05 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!is_at_least_two(stack))
		return ;
	last = get_last_node(stack);
	if (!last)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *a)
{
	rotate(a);
	write_op("ra");
}

void	rb(t_stack *b)
{
	rotate(b);
	write_op("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write_op("rr");
}
