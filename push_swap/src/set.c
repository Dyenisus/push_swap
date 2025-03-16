/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:36:38 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 17:42:04 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack *stack)
{
	t_node	*temp;
	int		i;

	temp = stack->top;
	i = 0;
	while (temp)
	{
		temp->position = i++;
		temp = temp->next;
	}
}

void	find_max(t_stack *stack)
{
	t_node	*temp;
	t_node	*max;

	if (is_stack_empty(stack))
	{
		stack->max = NULL;
		return ;
	}
	max = stack->top;
	temp = stack->top;
	while (temp->next)
	{
		if (temp->next->number > max->number)
			max = temp->next;
		temp = temp->next;
	}
	stack->max = max;
}

void	find_min(t_stack *stack)
{
	t_node	*temp;
	t_node	*min;

	if (is_stack_empty(stack))
	{
		stack->min = NULL;
		return ;
	}
	min = stack->top;
	temp = stack->top;
	while (temp->next)
	{
		if (temp->next->number < min->number)
			min = temp->next;
		temp = temp->next;
	}
	stack->min = min;
}

void	find_max_min(t_stack *stack)
{
	find_max(stack);	
	find_min(stack);
}
