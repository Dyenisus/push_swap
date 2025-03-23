/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:59:06 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/22 20:11:09 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	clear_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	if (is_stack_empty(stack))
		return ;
	temp = stack->top;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	free_chr(char **double_arr, char *arr)
{
	int	i;

	if (double_arr)
	{
		i = 0;
		while (double_arr[i])
			free(double_arr[i++]);
		free(double_arr);
		double_arr = NULL;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	free_int(int *arr)
{
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	print_error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	clear_exit(t_stack *a, t_stack *b, bool *flag, int exit)
{
	clear_stack(a);
	clear_stack(b);
	free(flag);
	if (exit)
		print_error();
}
