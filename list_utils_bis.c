/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:32 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:06:34 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*ft_lstadd_front(t_list *lst, t_list *new)
{
	if (new == NULL)
		return (lst);
	if (lst == NULL)
	{
		lst = new;
		return (lst);
	}
	new->next = lst;
	lst = new;
	return (new);
}

t_list	*ft_lstadd_back(t_list *lst, t_list *new)
{
	if (new == NULL)
		return (NULL);
	if (lst == NULL)
	{
		lst = new;
		return (NULL);
	}
	else
		ft_lstlast(lst)->next = new;
	return (lst);
}
