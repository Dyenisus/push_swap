/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:42:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/17 10:41:08 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument.h"

static	long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static	int	*add_lst(char **splitted, int *nbr_lst)
{
	int			i;
	long long	result;

	if (!splitted || !*splitted || !nbr_lst)
	{
		free_chr(splitted, NULL);
		free_int(nbr_lst);
		return (NULL);
	}
	i = 0;
	while (splitted[i])
	{
		result = ft_atol(splitted[i]);
		if (result < INT_MIN || result > INT_MAX)
			return (NULL);
		nbr_lst[i++] = result;
	}
	return (nbr_lst);
}

static	int	is_valid(int *nbr_lst, int len)
{
	int	i;
	int	j;

	if (!nbr_lst)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbr_lst[i] == nbr_lst[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	arg_len(char **splitted)
{
	int	len;

	len = 0;
	while (splitted[len])
		len++;
	return (len);
}

int	*arg_to_int(char **splitted)
{
	int	*nbr_lst;

	if (!splitted || !(*splitted))
		return (NULL);
	nbr_lst = (int *)malloc(sizeof(int) * arg_len(splitted));
	if (!nbr_lst)
	{
		free_chr(splitted, NULL);
		return (NULL);
	}
	nbr_lst = add_lst(splitted, nbr_lst);
	if (!nbr_lst)
	{
		free_chr(splitted, NULL);
		return (NULL);
	}
	if (!is_valid(nbr_lst, arg_len(splitted)))
	{
		free_chr(splitted, NULL);
		free_int(nbr_lst);
		return (NULL);
	}
	return (nbr_lst);
}
