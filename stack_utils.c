/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:36 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:34:31 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_order(t_stacks *stacks)
{
	t_list	*tempa;
	t_list	*tempb;

	tempa = stacks->a;
	tempb = stacks->b;
	if (tempb != NULL)
		return (0);
	while (tempa->next != NULL)
	{
		if (tempa->content > tempa->next->content)
			return (0);
		tempa = tempa->next;
	}
	return (1);
}

int	ft_order_list(t_list *list)
{
	t_list	*tempa;

	tempa = list;
	while (tempa->next != NULL)
	{
		if (tempa->content > tempa->next->content)
			return (0);
		tempa = tempa->next;
	}
	return (1);
}

int	iteration_smallest(t_list *temp_b, int s)
{
	int	i;

	i = 0;
	while (temp_b->content != s && temp_b->next != NULL)
	{
		i++;
		temp_b = temp_b->next;
	}
	return (i);
}

int	index_smallest(t_stacks *stacks)
{
	int		s;
	int		i;
	int		len;
	t_list	*temp_a;
	t_list	*temp_b;

	i = 1;
	len = ft_lstsize(stacks->a);
	temp_a = stacks->a;
	temp_b = stacks->a;
	if (temp_a->content < temp_a->next->content)
		s = temp_a->content;
	temp_a = temp_a->next;
	while (i < len)
	{
		if (temp_a->content < s)
			s = temp_a->content;
		temp_a = temp_a->next;
		i++;
	}
	return (iteration_smallest(temp_b, s));
}
