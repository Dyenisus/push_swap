/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:33:41 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 13:46:02 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->size == 2)
		sa(a);
	return ;
}

void	set_positions(t_stack *stack)
{
	t_node	*temp;
	int		i;

	temp = stack->top;
	i = 0;
	while (temp)
	{
		temp->position = i++;
		temp = temp->next;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
