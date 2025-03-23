/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:50:24 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/22 20:12:34 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	*flag;

	if (argc < 2)
		return (0);
	flag = (bool *)malloc(sizeof(bool));
	if (!flag)
		return (0);
	*flag = true;
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		clear_exit(a, b, flag, 1);
	handle_arg(a, argv, flag);
	if (!*flag)
		clear_exit(a, b, flag, 1);
	turk_algorithm(a, b, flag);
	if (!*flag)
		clear_exit(a, b, flag, 1);
	clear_exit(a, b, flag, 0);
	return (0);
}
