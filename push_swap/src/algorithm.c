/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:10:51 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 22:51:04 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static	void	ensure_sort(t_stack *a, bool *flag)
{
	find_min(a);
	if (!a->min)
	{
		*flag = false;
		return ;
	}
	default_rotate_a(a, a->min, flag);
	if (!*flag)
		return ;
}

static	void	optimal_push_to_a(t_stack *a, t_stack *b, bool *flag)
{
	t_node	*temp;

	if (is_stack_empty(b))
		return ;
	while (!is_stack_empty(b))
	{
		temp = b->top;
		temp->target = find_target_a(a, temp);
		if (!temp->target)
		{
			*flag = false;
			return ;
		}
		default_rotate_a(a, temp->target, flag);
		if (!*flag)
			return ;
		pa(a, b, flag);
		if (!*flag)
			return ;
	}
}

static	void	sort_three(t_stack *a, bool *flag)
{
	t_node	*biggest;
	
	find_max(a);
	if (!a->max)
	{
		*flag = false;
		return ;
	}
	biggest = a->max;
	if (biggest == a->top)
		ra(a, flag);
	else if (biggest == a->top->next)
		rra(a, flag);
	if (!*flag)
		return ;
	if (a->top->number > a->top->next->number)
		sa(a);
	if (!*flag)
		return ;
}

static	void	push_to_b(t_stack *a, t_stack *b, bool *flag)
{
	int	push_count;

	push_count = 2;
	while (a->size > 3 && push_count)
	{
		pb(b, a, flag);
		if (!*flag)
			return ;
		push_count--;
	}
	optimal_push_b(a, b, flag);
	if (!*flag)
		return ;
}

void print_stack(t_stack *stack, char *name)
{
    t_node *temp;
    
    if (!stack || !stack->top)
    {
        printf("%s: (empty)\n", name);
        return;
    }

    printf("%s (Top -> Bottom): ", name);
    temp = stack->top;
    while (temp)
    {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

void	turk_algorithm(t_stack *a, t_stack *b, bool *flag)
{
	if (is_stack_empty(a))
	{
		*flag = false;
		return ;
	}
	if (is_sorted(a, a->top))
		return ;
	if (a->size == 2)
	{
		sa(a);
		return ;
	}
	else if (a->size > 3)
		push_to_b(a, b, flag); // target is smaller than node but biggest among smaller numbers
	if (!*flag)
		return ;
	if (!is_sorted(a, a->top))
		sort_three(a, flag);
	if (!*flag)
		return ;
	optimal_push_to_a(a, b, flag); // target is bigger than node but smallest among bigger number
	if (!*flag)
		return ;
	if (!is_sorted(a, a->top))
		ensure_sort(a, flag);
}
