/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:54:49 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 00:03:07 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	number;

	if (is_stack_empty(b))
		return ;
	number = pop(b);
	push(a, number);
	write_op("pa");
}

void	pb(t_stack *b, t_stack *a)
{
	int	number;

	if (is_stack_empty(a))
		return ;
	number = pop(a);
	push(b, number);
	write_op("pb");
}
