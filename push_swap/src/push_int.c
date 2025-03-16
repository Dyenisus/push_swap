/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:47:08 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/16 22:57:32 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument.h"

void	push_nbr_lst(t_stack *a, char **splitted, int *nbr_lst, bool *flag)
{
	int		i;

	i = arg_len(splitted) - 1;
	free_chr(splitted, NULL);
	while (0 <= i)
	{
		push(a, nbr_lst[i--], flag);
		if (!*flag)
			break ;
	}
	free_int(nbr_lst);
}

void	handle_arg(t_stack *a, char **argv, bool *flag)
{
	char	**splitted;
	int		*nbr_lst;

	splitted = parse_arg(argv);
	if (!splitted)
	{
		*flag = false;
		return ;
	}
	nbr_lst = arg_to_int(splitted);
	if (!nbr_lst)
	{
		*flag = false;
		return ;
	}
	push_nbr_lst(a, splitted, nbr_lst, flag);
	if (!*flag)
	{
		free_chr(splitted, NULL);
		free_int(nbr_lst);
		return ;
	}
}
