/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:03:30 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 21:13:01 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "stack.h"

int	is_stack_empty(t_stack *stack);
int	is_at_least_two(t_stack *stack);
int	is_sorted(t_stack *stack, t_node *top);
int	is_same_half(t_node *node, t_node *target, t_stack *a, t_stack *b);

#endif