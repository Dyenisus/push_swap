/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:32:20 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 14:46:24 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_a(argv);
	b = init_stack();
	if (!b)
	{
		free_stack(a);
		exit_msg("Error: Stack 'b' cannot be initialized\n");
	}
	turk_algorithm(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
