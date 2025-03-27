/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:37:34 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 15:04:06 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*init_node(int nbr)
{
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->number = nbr;
	return (new);
}

t_stack	*init_stack(void)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	return (new);
}

static void	push_nbr_lst(t_stack *a, int *nbr_lst, int len)
{
	int		i;

	i = len - 1;
	while (0 <= i)
		push(a, nbr_lst[i--]);
	free(nbr_lst);
}

t_stack	*init_a(char **nbrs)
{
	t_stack	*a;
	char	**parsed;
	int		*nbr_lst;
	int		nbr_count;

	parsed = parse_arg(nbrs);
	if (!parsed)
		exit_msg("Error: Arguments cannot be parsed\n");
	nbr_count = nbrs_len(parsed);
	nbr_lst = arg_to_int_lst(parsed, nbr_count);
	a = init_stack();
	if (!a)
	{
		free(nbr_lst);
		exit_msg("Error: Stack 'a' cannot be initialized\n");
	}
	push_nbr_lst(a, nbr_lst, nbr_count);
	return (a);
}
