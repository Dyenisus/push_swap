/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:22:51 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 01:52:37 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nbrs_len(char **parsed)
{
	int	i;

	i = 0;
	while (parsed[i])
		i++;
	return (i);
}

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

t_node	*get_last_node(t_stack *stack)
{
	t_node	*last;

	if (is_stack_empty(stack))
		return (NULL);
	last = stack->top;
	while (last->next)
		last = last->next;
	return (last);
}

t_node	*get_prev_node(t_stack *stack, t_node *last)
{
	t_node	*prev;

	prev = stack->top;
	while (prev)
	{
		if (prev->next == last)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

t_node	*get_max_or_min(t_stack *stack, t_node *tmp, t_node *node, int md)
{
	if (is_stack_empty(stack))
		return (NULL);
	if (md == 0)
	{
		while (tmp)
		{
			if (tmp->number < node->number)
				node = tmp;
			tmp = tmp->next;
		}
	}
	else if (md == 1)
	{
		while (tmp)
		{
			if (tmp->number > node->number)
				node = tmp;
			tmp = tmp->next;
		}
	}
	return (node);
}
