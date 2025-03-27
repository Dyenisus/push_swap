/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:45:08 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 15:03:28 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack, int nbr)
{
	t_node	*new;

	new = init_node(nbr);
	if (!new)
		return ;
	if (stack->top)
		new->next = stack->top;
	stack->top = new;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		number;

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
