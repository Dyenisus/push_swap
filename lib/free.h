/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:11:53 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/15 17:27:51 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "check.h"

void	clear_stack(t_stack *stack);
void	free_chr(char **double_arr, char *arr);
void	free_int(int *arr);
void	print_error(void);
void	clear_exit(t_stack *a, t_stack *b, bool *flag, int exit);

#endif