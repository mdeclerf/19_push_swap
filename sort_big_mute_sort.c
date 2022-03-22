/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_mute_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:22 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/12 11:07:07 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks	*three_bis_mute(t_stacks *stacks)
{
	if ((stacks->a->content < stacks->a->next->content)
		&& (stacks->a->content < stacks->a->next->next->content))
	{
		stacks = ft_swap_mute(stacks, "sa" );
		stacks = ft_rotate_mute(stacks, "ra");
		return (stacks);
	}
	else if ((stacks->a->content < stacks->a->next->content)
		&& (stacks->a->content > stacks->a->next->next->content))
	{
		stacks = ft_rotateR_mute(stacks, "rra");
		return (stacks);
	}
	return (stacks);
}

t_stacks	*three_mute(t_stacks *stacks)
{
	if ((stacks->a->content > stacks->a->next->content)
		&& (stacks->a->content < stacks->a->next->next->content))
	{
		stacks = ft_swap_mute(stacks, "sa");
		return (stacks);
	}
	else if ((stacks->a->content > stacks->a->next->content)
		&& (stacks->a->content > stacks->a->next->content)
		&& (stacks->a->next->content > stacks->a->next->next->content))
	{
		stacks = ft_swap_mute(stacks, "sa");
		stacks = ft_rotateR_mute(stacks, "rra");
		return (stacks);
	}
	else if ((stacks->a->content > stacks->a->next->content)
		&& (stacks->a->content > stacks->a->next->content)
		&& (stacks->a->next->content < stacks->a->next->next->content))
	{
		stacks = ft_rotate_mute(stacks, "ra");
		return (stacks);
	}
	stacks = three_bis_mute(stacks);
	return (stacks);
}

t_stacks	*sort_mute_loop(t_stacks *copy)
{
	int	pos;

	pos = index_smallest(copy);
	if (pos < ft_lstsize(copy->a) / 2)
	{
		while (pos != 0)
		{
			copy = ft_rotate_mute(copy, "ra");
			pos = index_smallest(copy);
		}
	}
	else if (pos >= ft_lstsize(copy->a) / 2)
	{
		while (pos != 0)
		{
			copy = ft_rotateR_mute(copy, "rra");
			pos = index_smallest(copy);
		}
	}
	copy = ft_pb_mute(copy);
	return (copy);
}

t_stacks	*sort_mute(t_stacks *copy)
{
	int	order;

	order = ft_order_list(copy->a);
	while (ft_lstsize(copy->a) != 3)
		copy = sort_mute_loop(copy);
	order = ft_order_list(copy->a);
	if (order == 0)
		copy = three_mute(copy);
	while (copy->b != NULL)
		copy = ft_pa_mute(copy);
	return (copy);
}
