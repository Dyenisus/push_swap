/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:26:49 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/17 10:33:29 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

t_node	*find_target_b(t_stack *target_stack, t_node *node)
{
	t_node	*target;
	t_node	*temp;

	if (is_stack_empty(target_stack) || !node)
		return (NULL);
	find_max_min(target_stack);
	if (!target_stack->max || !target_stack->min)
		return (NULL);
	if (node->number > target_stack->max->number
		|| node->number < target_stack->min->number)
		return (target_stack->max);
	target = NULL;
	temp = target_stack->top;
	while (temp)
	{
		if (temp->number < node->number)
		{
			if (!target || temp->number > target->number)
				target = temp;
		}
		temp = temp->next;
	}
	return (target);
}

t_node	*find_target_a(t_stack *target_stack, t_node *node)
{
	t_node	*target;
	t_node	*temp;

	if (is_stack_empty(target_stack) || !node)
		return (NULL);
	find_max_min(target_stack);
	if (!target_stack->max || !target_stack->min)
		return (NULL);
	if (node->number < target_stack->min->number
		|| node->number > target_stack->max->number)
		return (target_stack->min);
	target = NULL;
	temp = target_stack->top;
	while (temp)
	{
		if (temp->number > node->number)
		{
			if (!target || temp->number < target->number)
				target = temp;
		}
		temp = temp->next;
	}
	return (target);
}
