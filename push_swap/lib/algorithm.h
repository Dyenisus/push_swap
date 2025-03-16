/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:20:01 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 21:41:41 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "argument.h"
#include <stdio.h> //

void	optimal_rotate_b(t_stack *a, t_stack *b, t_node *cheapest, bool *flag);
void	default_rotate_b(t_stack *a, t_stack *b, t_node *cheapest, bool *flag);
void	default_rotate_a(t_stack *a, t_node *target, bool *flag);
void	optimal_push_b(t_stack *a, t_stack *b, bool *flag);
t_node	*find_target_b(t_stack *target_stack, t_node *node);
t_node	*find_target_a(t_stack *target_stack, t_node *node);
t_node	*find_cheapest_b(t_stack *a, t_stack *b, bool *flag);
void	turk_algorithm(t_stack *a, t_stack *b, bool *flag);
void print_stack(t_stack *stack, char *name);

#endif