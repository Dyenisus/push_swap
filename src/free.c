/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:43:15 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/26 23:31:26 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_2d(char **two)
{
	int	i;

	if (!two)
		return ;
	i = 0;
	while (two[i])
		free(two[i++]);
	free(two);
	two = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(stack);
}
