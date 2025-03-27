/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:38:29 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/27 14:49:52 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	char	*joiner(char *nbr, char *joined)
{
	char	*temp;
	char	*new_joined;

	temp = ft_strjoin(joined, " ");
	free(joined);
	if (!temp)
		return (NULL);
	new_joined = ft_strjoin(temp, nbr);
	free(temp);
	if (!new_joined)
		return (NULL);
	return (new_joined);
}

static	char	*join_all( char **nbrs)
{
	int		i;
	char	*joined;
	char	*temp;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	i = 1;
	while (nbrs[i])
	{
		temp = joiner(nbrs[i++], joined);
		if (!temp)
			return (NULL);
		joined = temp;
	}
	return (joined);
}

static	int	is_valid(char *str_nbr)
{
	int	i;

	if (!str_nbr || !*str_nbr)
		return (0);
	i = 0;
	if ((str_nbr[0] == '-' || str_nbr[0] == '+'))
		i++;
	if (!str_nbr[i])
		return (0);
	while (str_nbr[i])
	{
		if (!ft_isdigit(str_nbr[i++]))
			return (0);
	}
	if ((str_nbr[0] == '-' || str_nbr[0] == '+') && i > 11)
		return (0);
	if (!(str_nbr[0] == '-' || str_nbr[0] == '+') && i > 10)
		return (0);
	return (1);
}

static	char	**splitter(char *src, char c)
{
	char	**splitted;

	if (!src)
		return (NULL);
	splitted = ft_split(src, c);
	free(src);
	if (!splitted)
		return (NULL);
	return (splitted);
}

char	**parse_arg(char **nbrs)
{
	char	*joined;
	char	**splitted;
	int		i;

	if (!nbrs || !(*nbrs))
		return (NULL);
	joined = join_all(nbrs);
	if (!joined)
		return (NULL);
	splitted = splitter(joined, ' ');
	if (!splitted)
	{
		free(joined);
		return (NULL);
	}
	i = 0;
	while (splitted[i])
	{
		if (!is_valid(splitted[i++]))
		{
			free_2d(splitted);
			return (NULL);
		}
	}
	return (splitted);
}
