/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:54 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:06:56 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks	*ft_pa(t_stacks *stacks)
{
	t_list	*new;

	if (stacks->b)
	{
		new = stacks->b->next;
		stacks->b->next = stacks->a;
		stacks->a = stacks->b;
		stacks->b = new;
	}
	ft_putstr("pa\n");
	return (stacks);
}

t_stacks	*ft_pb(t_stacks *stacks)
{
	t_list	*new;

	if (stacks->a)
	{
		new = stacks->a->next;
		stacks->a->next = stacks->b;
		stacks->b = stacks->a;
		stacks->a = new;
	}
	ft_putstr("pb\n");
	return (stacks);
}

t_stacks	*ft_pa_mute(t_stacks *stacks)
{
	t_list	*new;

	if (stacks->b)
	{
		new = stacks->b->next;
		stacks->b->next = stacks->a;
		stacks->a = stacks->b;
		stacks->b = new;
	}
	return (stacks);
}

t_stacks	*ft_pb_mute(t_stacks *stacks)
{
	t_list	*new;

	if (stacks->a)
	{
		new = stacks->a->next;
		stacks->a->next = stacks->b;
		stacks->b = stacks->a;
		stacks->a = new;
	}
	return (stacks);
}
