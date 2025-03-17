/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:46:15 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/17 10:32:33 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*target;
	int				number;
	int				cost;
	int				position;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*max;
	t_node	*min;
	int		size;
}	t_stack;

t_node	*init_node(int nbr);
t_stack	*init_stack(void);
void	set_positions(t_stack *stack);
void	find_max(t_stack *stack);
void	find_min(t_stack *stack);
void	find_max_min(t_stack *stack);
t_node	*get_last_node(t_stack *stack);

#endif