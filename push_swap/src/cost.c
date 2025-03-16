/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:04:14 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 20:53:17 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static	int	calculate_move(t_stack *target_stack, t_node *target)
{
	int		move_count;

	move_count = target->position;
	if (move_count == -1)
		return (-1);
	if (move_count >= target_stack->size / 2)
		move_count = target_stack->size - move_count;
	return (move_count);
}

static	int	calculate_cost(t_node *node, t_node *target, t_stack *a, t_stack *b)
{
	int	count_a;
	int	count_b;

	count_a = calculate_move(a, node);
	if (count_a == -1)
		return (-1);
	count_b = calculate_move(b, target);
	if (count_b == -1)
		return (-1);
	if (is_same_half(node, target, a, b))
	{
		if (count_a > count_b)
			return (count_a);
		return (count_b);
	}
	return (count_a + count_b);
}

static	void	calculate_all_cost(t_stack *a, t_stack *b, bool *flag)
{
	t_node *current;
	t_node *target;

	set_positions(a);
	set_positions(b);
	current = a->top;
	while (current)
	{
		target = find_target_b(b, current);
		current->cost = calculate_cost(current, target, a, b);
		if (current->cost == -1)
		{
			*flag = false;
			return ;
		}
		current = current->next;
	}
}

t_node	*find_cheapest_b(t_stack *a, t_stack *b, bool *flag)
{
	t_node *current;
	t_node *cheapest;

	if (is_stack_empty(a) || is_stack_empty(b))
		return (NULL);
	calculate_all_cost(a, b, flag);
	find_max_min(b);
	cheapest = a->top;
	current = a->top;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->target = find_target_b(b, cheapest);
	return (cheapest);
}
