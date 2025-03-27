/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:19:57 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 18:58:19 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_target_b(t_stack *b, t_node *node)
{
	t_node	*current;
	t_node	*target;
	t_node	*max;
	t_node	*min;

	if (!b || !b->top || !node)
		return (NULL);
	set_positions(b);
	max = get_max_or_min(b, b->top, b->top, 1);
	min = get_max_or_min(b, b->top, b->top, 0);
	if (node->number > max->number || node->number < min->number)
		return (max);
	target = NULL;
	current = b->top;
	while (current)
	{
		if (node->number > current->number)
		{
			if (!target || current->number > target->number)
				target = current;
		}
		current = current->next;
	}
	return (target);
}

t_node	*find_target_a(t_stack *a, t_node *node)
{
	t_node	*current;
	t_node	*target;
	t_node	*max;
	t_node	*min;

	if (!a || !a->top || !node)
		return (NULL);
	set_positions(a);
	max = get_max_or_min(a, a->top, a->top, 1);
	min = get_max_or_min(a, a->top, a->top, 0);
	if (node->number < min->number || node->number > max->number)
		return (min);
	target = NULL;
	current = a->top;
	while (current)
	{
		if (node->number < current->number)
		{
			if (!target || current->number < target->number)
				target = current;
		}
		current = current->next;
	}
	return (target);
}
