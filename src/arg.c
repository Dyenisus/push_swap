/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:07:26 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 19:54:51 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	*add_lst(char **parsed, int *nbr_lst)
{
	int			i;
	long long	result;

	i = 0;
	while (parsed[i])
	{
		result = ft_atol(parsed[i]);
		if (result < INT_MIN || result > INT_MAX)
		{
			if (nbr_lst)
				free(nbr_lst);
			return (NULL);
		}
		nbr_lst[i++] = result;
	}
	free_2d(parsed);
	return (nbr_lst);
}

static	int	is_not_one(int *nbr_lst, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbr_lst[i] == nbr_lst[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*arg_to_int_lst(char **parsed, int nbr_count)
{
	int	*nbr_lst;

	nbr_lst = (int *)ft_calloc(nbr_count, sizeof(int));
	if (!nbr_lst)
	{
		free_2d(parsed);
		exit_msg("Error: Number list cannot be initialized\n");
	}
	nbr_lst = add_lst(parsed, nbr_lst);
	if (!nbr_lst)
	{
		free_2d(parsed);
		exit_msg("Error: Numbers are not Integers\n");
	}
	if (is_not_one(nbr_lst, nbr_count))
	{
		free(nbr_lst);
		exit_msg("Error: More than one same number\n");
	}
	return (nbr_lst);
}
