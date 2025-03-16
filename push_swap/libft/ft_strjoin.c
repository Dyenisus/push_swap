/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:14:35 by yesoytur          #+#    #+#             */
/*   Updated: 2024/10/28 13:15:07 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*n_s;

	if (!s1 || !s2)
		return (0);
	else
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		n_s = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
		if (!n_s)
			return (NULL);
		ft_strlcpy(n_s, s1, len_s1 + 1);
		ft_strlcat(n_s, s2, len_s1 + len_s2 + 1);
	}
	return (n_s);
}
