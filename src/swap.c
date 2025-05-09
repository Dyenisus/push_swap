/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:56:01 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 00:21:48 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!is_at_least_two(stack))
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a)
{
	swap(a);
	write_op("sa");
}

void	sb(t_stack *b)
{
	swap(b);
	write_op("sb");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write_op("ss");
}
