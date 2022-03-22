/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:00 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:07:02 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*ft_ra_rb(t_list *list)
{
	t_list	*temp;
	t_list	*first;

	if (list && list->next)
	{
		temp = list;
		list = list->next;
		first = list;
		temp->next = NULL;
		while (list->next)
		{
			list = list->next;
		}
		list->next = temp;
		list = first;
	}
	return (list);
}

t_stacks	*ft_rotate(t_stacks *stacks, char *str)
{
	if (str[1] == 'a')
	{
		stacks->a = ft_ra_rb(stacks->a);
		ft_putstr("ra\n");
	}
	else if (str[1] == 'b')
	{
		stacks->b = ft_ra_rb(stacks->b);
		ft_putstr("rb\n");
	}
	else if (str[1] == 'r')
	{
		stacks->a = ft_ra_rb(stacks->a);
		stacks->b = ft_ra_rb(stacks->b);
		ft_putstr("rr\n");
	}
	return (stacks);
}

t_stacks	*ft_rotate_mute(t_stacks *stacks, char *str)
{
	if (str[1] == 'a')
		stacks->a = ft_ra_rb(stacks->a);
	else if (str[1] == 'b')
		stacks->b = ft_ra_rb(stacks->b);
	else if (str[1] == 'r')
	{
		stacks->a = ft_ra_rb(stacks->a);
		stacks->b = ft_ra_rb(stacks->b);
	}
	return (stacks);
}
