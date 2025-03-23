/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:11:17 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 21:36:20 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static	void	rotate(t_stack *stack, bool *flag)
{
	t_node	*first;
	t_node	*last;

	if (!is_at_least_two(stack))
		return ;
	last = get_last_node(stack);
	if (!last)
	{
		*flag = false;
		return ;
	}
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *a, bool *flag)
{
	rotate(a, flag);
	if (!*flag)
		return ;
	write_op("ra");
}

void	rb(t_stack *b, bool *flag)
{
	rotate(b, flag);
	if (!*flag)
		return ;
	write_op("rb");
}

void	rr(t_stack *a, t_stack *b, bool *flag)
{
	rotate(a, flag);
	if (!*flag)
		return ;
	rotate(b, flag);
	if (!*flag)
		return ;
	write_op("rr");
}
