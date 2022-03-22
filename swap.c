/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:54 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:07:56 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*ft_sa_sb(t_list *lst)
{
	int		first;
	int		second;
	int		len;
	t_list	*return_list;
	t_list	*tmp;

	len = ft_lstsize(lst);
	if (len < 2)
		return (lst);
	tmp = lst;
	return_list = lst;
	first = tmp->content;
	tmp = tmp->next;
	second = tmp->content;
	lst->content = second;
	lst = lst->next;
	lst->content = first;
	return (return_list);
}

t_stacks	*ft_swap(t_stacks *stacks, char *arg)
{
	if (arg[1] == 'a')
	{
		stacks->a = ft_sa_sb(stacks->a);
		ft_putstr("sa\n");
	}
	else if (arg[1] == 'b')
	{
		stacks->b = ft_sa_sb(stacks->b);
		ft_putstr("sb\n");
	}
	else if (arg[1] == 's')
	{
		stacks->a = ft_sa_sb(stacks->a);
		stacks->b = ft_sa_sb(stacks->b);
		ft_putstr("ss\n");
	}
	return (stacks);
}

t_stacks	*ft_swap_mute(t_stacks *stacks, char *arg)
{
	if (arg[1] == 'a')
		stacks->a = ft_sa_sb(stacks->a);
	else if (arg[1] == 'b')
		stacks->b = ft_sa_sb(stacks->b);
	else if (arg[1] == 's')
	{
		stacks->a = ft_sa_sb(stacks->a);
		stacks->b = ft_sa_sb(stacks->b);
	}
	return (stacks);
}
