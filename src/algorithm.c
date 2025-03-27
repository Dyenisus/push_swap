/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:24:01 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 19:26:55 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (a->size > 3 && b->size < 2)
		pb(b, a);
	while (a->size > 3)
	{
		cheapest = find_cheap(b, a, find_target_b);
		move_stacks(a, b, cheapest, cheapest->target);
		pb(b, a);
	}
}

static void	sort_three(t_stack *stack)
{
	t_node	*biggest;

	if (is_sorted(stack) || stack->size != 3)
		return ;
	biggest = get_max_or_min(stack, stack->top, stack->top, 1);
	if (biggest == stack->top)
		ra(stack);
	else if (biggest == stack->top->next)
		rra(stack);
	if (stack->top->number > stack->top->next->number)
		sa(stack);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (b->size > 0)
	{
		cheapest = find_cheap(a, b, find_target_a);
		move_stacks(a, b, cheapest->target, cheapest);
		pa(a, b);
	}
}

static void	ensure_sort(t_stack *stack)
{
	t_node	*min;

	if (is_sorted(stack))
		return ;
	set_positions(stack);
	min = get_max_or_min(stack, stack->top, stack->top, 0);
	if (min->position <= stack->size / 2)
	{
		while (stack->top != min)
			ra(stack);
	}
	else
	{
		while (stack->top != min)
			rra(stack);
	}
}

void	turk_algorithm(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	sort_two(a);
	push_to_b(a, b);
	sort_three(a);
	push_to_a(a, b);
	ensure_sort(a);
}
