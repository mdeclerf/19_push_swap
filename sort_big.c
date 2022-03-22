/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:29 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 17:09:07 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_lstiter(t_list *lst, int i)
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		lst->index = i;
		i++;
		lst = lst->next;
	}
}

t_stacks	*indexing(char **argv)
{
	t_stacks	*copy;
	int			i;

	i = 0;
	copy = stacks_init(argv);
	copy = sort_mute(copy);
	ft_lstiter(copy->a, i);
	return (copy);
}

t_stacks	*association(t_stacks *stacks, t_stacks *copy)
{
	t_list	*temp;
	t_list	*backup;

	backup = stacks->a;
	while (backup)
	{
		temp = copy->a;
		while (temp != NULL)
		{
			if (backup->content == temp->content)
			{
				backup->index = temp->index;
				break ;
			}
			temp = temp->next;
		}
		backup = backup->next;
	}
	free_stacks(copy);
	return (stacks);
}

t_stacks	*sort_big(t_stacks *stacks, int argc, int zero)
{
	int			i;
	int			count;

	i = zero;
	while (--i > 0)
	{
		count = argc;
		while (--count > 0)
		{
			if (stacks->a->binary[i] == '0')
				stacks = ft_pb(stacks);
			else if (stacks->a->binary[i] == '1')
				stacks = ft_rotate(stacks, "ra");
		}
		while (stacks->b)
			stacks = ft_pa(stacks);
	}
	return (stacks);
}
