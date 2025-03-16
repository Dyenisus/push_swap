/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:39:48 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/13 23:11:45 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_H
# define ARGUMENT_H

# include "operations.h"

char	**parse_arg(char **argv);
int	arg_len(char **splitted);
int	*arg_to_int(char **splitted);
void	push_nbr_lst(t_stack *a, char **splitted, int *nbr_lst, bool *flag);
void	handle_arg(t_stack *a, char **argv, bool *flag);

#endif