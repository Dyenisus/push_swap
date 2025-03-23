/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:18:11 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/13 21:50:47 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	push(t_stack *stack, int nbr, bool *flag)
{
	t_node	*new;

	new = init_node(nbr);
	if (!new)
	{
		*flag = false;
		return ;
	}
	if (stack->top)
		new->next = stack->top;
	stack->top = new;
	stack->size++;
}

int	pop(t_stack *stack, bool *flag)
{
	t_node	*temp;
	int		number;

	if (is_stack_empty(stack))
	{
		*flag = false;
		return (INT_MIN);
	}
	number = stack->top->number;
	temp = stack->top;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (number);
}

void	write_op(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
