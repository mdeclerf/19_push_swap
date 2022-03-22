/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:04 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/12 11:05:41 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks	*find_small_ra_pa(t_stacks *stacks)
{
	int	pos;

	pos = index_smallest(stacks);
	if (pos < ft_lstsize(stacks->a) / 2)
	{
		while (pos != 0)
		{
			stacks = ft_rotate(stacks, "ra");
			pos = index_smallest(stacks);
		}
	}
	else if (pos >= ft_lstsize(stacks->a) / 2)
	{
		while (pos != 0)
		{
			stacks = ft_rotateR(stacks, "rra");
			pos = index_smallest(stacks);
		}
	}
	stacks = ft_pb(stacks);
	return (stacks);
}

t_stacks	*four_five(t_stacks *stacks)
{
	int	order;

	while (ft_lstsize(stacks->a) != 3)
		stacks = find_small_ra_pa(stacks);
	order = ft_order_list(stacks->a);
	if (order == 0)
		stacks = three(stacks);
	while (stacks->b != NULL)
		stacks = ft_pa(stacks);
	return (stacks);
}
