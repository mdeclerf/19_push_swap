/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateR.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:08 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:07:10 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*ft_rra_rrb(t_list *lst)
{
	t_list	*tmp;
	int		len;
	int		last;
	t_list	*tmpb;

	len = ft_lstsize(lst);
	if (len < 2)
		return (lst);
	tmpb = ft_beforelstlast(lst);
	last = tmpb->content;
	tmp = ft_lstlast(lst);
	tmp->next = lst;
	tmpb->next = NULL;
	lst = tmp;
	return (lst);
}

t_stacks	*ft_rotateR(t_stacks *stacks, char *arg)
{
	if (arg[1] == 'r' && arg[2] == 'a')
	{
		stacks->a = ft_rra_rrb(stacks->a);
		ft_putstr("rra\n");
	}
	else if (arg[1] == 'r' && arg[2] == 'b')
	{
		stacks->b = ft_rra_rrb(stacks->b);
		ft_putstr("rrb\n");
	}
	else if (arg[1] == 'r' && arg[2] == 'r')
	{
		stacks->a = ft_rra_rrb(stacks->a);
		stacks->b = ft_rra_rrb(stacks->b);
		ft_putstr("rrr\n");
	}
	return (stacks);
}

t_stacks	*ft_rotateR_mute(t_stacks *stacks, char *arg)
{
	if (arg[1] == 'r' && arg[2] == 'a')
		stacks->a = ft_rra_rrb(stacks->a);
	else if (arg[1] == 'r' && arg[2] == 'b')
		stacks->b = ft_rra_rrb(stacks->b);
	else if (arg[1] == 'r' && arg[2] == 'r')
	{
		stacks->a = ft_rra_rrb(stacks->a);
		stacks->b = ft_rra_rrb(stacks->b);
	}
	return (stacks);
}
