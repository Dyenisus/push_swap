/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:25:48 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 19:26:47 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				number;
	int				position;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// free
void		free_2d(char **two);
void		free_stack(t_stack *stack);

// parse
char		**parse_arg(char **nbrs);

// exit
void		exit_msg(char *msg);

// utils
int			nbrs_len(char **parsed);
long long	ft_atol(const char *str);
t_node		*get_last_node(t_stack *stack);
t_node		*get_prev_node(t_stack *stack, t_node *last);
t_node		*get_max_or_min(t_stack *stack, t_node *tmp, t_node *node, int md);

// arg
int			*arg_to_int_lst(char **parsed, int nbr_count);

// init
t_node		*init_node(int nbr);
t_stack		*init_stack(void);
t_stack		*init_a(char **nbrs);

// operations
void		push(t_stack *stack, int nbr);
int			pop(t_stack *stack);
void		write_op(const char *str);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *b, t_stack *a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

// check
int			is_stack_empty(t_stack *stack);
int			is_at_least_two(t_stack *stack);
int			is_sorted(t_stack *stack);

// algorithm
void		turk_algorithm(t_stack *a, t_stack *b);

// algorithm helper
void	sort_two(t_stack *a);
void	set_positions(t_stack *stack);
int		max(int a, int b);
int		abs(int a);

// cost
int		calculate_move(t_stack *stack, t_node *node);
int		calculate_cost(t_node *node, t_node *target, t_stack *a, t_stack *b);
t_node	*find_cheap(t_stack *a, t_stack *b, t_node *(*f)(t_stack *, t_node *));

// move
void	move_stacks(t_stack *a, t_stack *b, t_node *a_node, t_node *b_node);

// target
t_node	*find_target_b(t_stack *b, t_node *node);
t_node	*find_target_a(t_stack *a, t_node *node);

#endif