/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:14:43 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 19:04:25 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_stacks(t_stack *a, t_stack *b, t_node *a_node, t_node *b_node)
{
	int		cost_a;
	int		cost_b;

	cost_a = calculate_move(a, a_node);
	cost_b = calculate_move(b, b_node);
	while (cost_a > 0 && cost_b > 0 && (cost_a--, cost_b--))
		rr(a, b);
	while (cost_a < 0 && cost_b < 0 && (cost_a++, cost_b++))
		rrr(a, b);
	while (cost_a > 0 && cost_a--)
		ra(a);
	while (cost_a < 0 && cost_a++)
		rra(a);
	while (cost_b > 0 && cost_b--)
		rb(b);
	while (cost_b < 0 && cost_b++)
		rrb(b);
}
