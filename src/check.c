/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:03:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 15:11:51 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	is_sorted(t_stack *stack)
{
	t_node	*temp;

	if (is_stack_empty(stack))
		return (1);
	temp = stack->top;
	while (temp->next)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}
