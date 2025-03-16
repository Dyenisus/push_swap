/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:03:20 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 20:58:19 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	is_stack_empty(t_stack *stack)
{
	if (!stack || !(stack->top))
		return (1);
	return (0);
}

int	is_at_least_two(t_stack *stack)
{
	if (is_stack_empty(stack) || !(stack->top->next))
		return (0);
	return (1);
}

int	is_sorted(t_stack *stack, t_node *top)
{
	if (!is_at_least_two(stack))
		return (1);
	while (top->next)
	{
		if (top->number > top->next->number)
			return (0);
		top = top->next;
	}
	return (1);
}

int	is_same_half(t_node *node, t_node *target, t_stack *a, t_stack *b)
{
	if ((node->position <= a->size / 2 && target->position <= b->size / 2))
		return (1);
	if ((node->position > a->size / 2 && target->position > b->size / 2))
		return (2);
	return (0);
}

