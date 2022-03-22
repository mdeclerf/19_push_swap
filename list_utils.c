/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:39 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 13:43:23 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*ft_lstnew_index(int number, int i)
{
	t_list	*mylist;

	mylist = malloc(sizeof(t_list));
	if (! mylist)
		return (NULL);
	mylist->content = number;
	mylist->index = i;
	mylist->binary = NULL;
	mylist->next = NULL;
	return (mylist);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_beforelstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
