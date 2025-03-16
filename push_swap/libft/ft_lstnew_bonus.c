/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:02:15 by yesoytur          #+#    #+#             */
/*   Updated: 2024/11/01 12:15:02 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_list;

	n_list = (t_list *)malloc(sizeof(t_list));
	if (!n_list)
		return (NULL);
	n_list -> content = content;
	n_list -> next = NULL;
	return (n_list);
}
