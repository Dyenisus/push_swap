/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:01:55 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 18:49:06 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_move(t_stack *stack, t_node *node)
{
	if (node->position <= stack->size / 2)
		return (node->position); // rotate up (ra/rb)
	else
		return (-(stack->size - node->position)); // reverse rotate (rra/rrb)
}

int	calculate_cost(t_node *node, t_node *target, t_stack *s1, t_stack *s2)
{
	int	cost_s1;
	int	cost_s2;

	cost_s1 = calculate_move(s1, node);
	cost_s2 = calculate_move(s2, target);
	if (cost_s1 >= 0 && cost_s2 >= 0)
		return (max(cost_s1, cost_s2)); // use rr
	else if (cost_s1 < 0 && cost_s2 < 0)
		return (max(-cost_s1, -cost_s2)); // use rrr
	else
		return (abs(cost_s1) + abs(cost_s2)); // rotate separately
}

t_node	*find_cheap(t_stack *s, t_stack *s1, t_node *(*f)(t_stack *, t_node *))
{
	t_node	*current;
	t_node	*cheapest;
	int		lowest_cost;
	int		current_cost;

	if (!s1 || !s1->top)
		return (NULL);
	set_positions(s);
	set_positions(s1);
	current = s1->top;
	cheapest = NULL;
	lowest_cost = INT_MAX;
	while (current)
	{
		current->target = f(s, current);
		current_cost = calculate_cost(current, current->target, s1, s);
		if (current_cost < lowest_cost)
		{
			lowest_cost = current_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
