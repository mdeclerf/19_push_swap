/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:08:01 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:12:29 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks	*two(t_stacks *stacks)
{
	stacks = ft_swap(stacks, "sa");
	return (stacks);
}

t_stacks	*three_bis(t_stacks *stacks)
{
	if ((stacks->a->content < stacks->a->next->content)
		&& (stacks->a->content < stacks->a->next->next->content))
	{
		stacks = ft_swap(stacks, "sa" );
		stacks = ft_rotate(stacks, "ra");
		return (stacks);
	}
	else if ((stacks->a->content < stacks->a->next->content)
		&& (stacks->a->content > stacks->a->next->next->content))
	{
		stacks = ft_rotateR(stacks, "rra");
		return (stacks);
	}
	return (stacks);
}

t_stacks	*three(t_stacks *stacks)
{
	if ((stacks->a->content > stacks->a->next->content)
		&& (stacks->a->content < stacks->a->next->next->content))
	{
		stacks = ft_swap(stacks, "sa");
		return (stacks);
	}
	else if ((stacks->a->content > stacks->a->next->content)
		&& (stacks->a->content > stacks->a->next->content)
		&& (stacks->a->next->content > stacks->a->next->next->content))
	{
		stacks = ft_swap(stacks, "sa");
		stacks = ft_rotateR(stacks, "rra");
		return (stacks);
	}
	else if ((stacks->a->content > stacks->a->next->content)
		&& (stacks->a->content > stacks->a->next->content)
		&& (stacks->a->next->content < stacks->a->next->next->content))
	{
		stacks = ft_rotate(stacks, "ra");
		return (stacks);
	}
	stacks = three_bis(stacks);
	return (stacks);
}
