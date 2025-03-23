/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:16:42 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 22:42:08 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_stack *a, t_stack *b, bool *flag)
{
	int	number;

	if (is_stack_empty(b))
		return ;
	number = pop(b, flag);
	if (!*flag)
		return ;
	push(a, number, flag);
	if (!*flag)
		return ;
	write_op("pa");
}

void	pb(t_stack *b, t_stack *a, bool *flag)
{
	int	number;

	if (is_stack_empty(a))
		return ;
	number = pop(a, flag);
	if (!*flag)
		return ;
	push(b, number, flag);
	if (!*flag)
		return ;
	write_op("pb");
}
