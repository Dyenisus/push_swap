/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:37:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 22:43:43 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "free.h"

void	push(t_stack *stack, int nbr, bool *flag);
int	pop(t_stack *stack, bool *flag);
void	write_op(const char *str);
void	pa(t_stack *a, t_stack *b, bool *flag);
void	pb(t_stack *b, t_stack *a, bool *flag);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a, bool *flag);
void	rb(t_stack *b, bool *flag);
void	rr(t_stack *a, t_stack *b, bool *flag);
void	rra(t_stack *a, bool *flag);
void	rrb(t_stack *b, bool *flag);
void	rrr(t_stack *a, t_stack *b, bool *flag);

#endif