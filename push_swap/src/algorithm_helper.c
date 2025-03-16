/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:09:54 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 21:57:35 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	optimal_rotate_b(t_stack *a, t_stack *b, t_node *cheapest, bool *flag)
{
	while (a->top != cheapest && b->top != cheapest->target)
	{
		set_positions(a);
		set_positions(b);
		if (is_same_half(cheapest, cheapest->target, a, b) == 1)
			rr(a, b, flag);
		else if (is_same_half(cheapest, cheapest->target, a, b) == 2)
			rrr(a, b, flag);
		if (!*flag)
			return ;
	}
}

void	default_rotate_b(t_stack *a, t_stack *b, t_node *cheapest, bool *flag)
{
	while (a->top != cheapest)
	{
		set_positions(a);
		if (cheapest->position <= a->size / 2)
			ra(a, flag);
		else if (cheapest->position > a->size / 2)
			rra(a, flag);
		if (!*flag)
			return ;
	}
	while (b->top != cheapest->target)
	{
		set_positions(b);
		if (cheapest->target->position <= b->size / 2)
			rb(b, flag);
		else if (cheapest->target->position > b->size / 2)
			rrb(b, flag);
		if (!*flag)
			return ;
	}
}

void	default_rotate_a(t_stack *a, t_node *target, bool *flag)
{
	while (a->top != target)
	{
		set_positions(a);
		if (target->position <= a->size / 2)
			ra(a, flag);
		else if (target->position > a->size / 2)
			rra(a, flag);
		if (!*flag)
			return ;
	}
}

void	optimal_push_b(t_stack *a, t_stack *b, bool *flag)
{
	t_node	*cheapest;

	if (is_stack_empty(a))
	{
		*flag = false;
		return ;
	}
	while (a->size > 3)
	{
		cheapest = find_cheapest_b(a, b, flag);
		if (!cheapest)
		{
			*flag = false;
			return ;
		}
		if (is_same_half(cheapest, cheapest->target, a, b))
			optimal_rotate_b(a, b, cheapest, flag);
		else
			default_rotate_b(a, b, cheapest, flag);
		if (!*flag)
			return ;
		pb(b, a, flag);
		if (!*flag)
			return ;
	}
}
