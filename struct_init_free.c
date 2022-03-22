/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:47 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:36:28 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks	*stacks_init(char **argv)
{
	t_stacks	*stacks;
	t_list		*new;
	t_list		*lst;
	int			i;
	int			j;

	j = 0;
	stacks = (t_stacks *)malloc(sizeof(t_stacks) + 1);
	if (! stacks)
		return (NULL);
	if (! argv[0] || ! argv[1])
		return (stacks);
	lst = ft_lstnew_index(ft_atoi(argv[1]), j);
	i = 2;
	while (argv[i])
	{
		new = ft_lstnew_index(ft_atoi(argv[i]), j);
		lst = ft_lstadd_back(lst, new);
		i++;
	}
	stacks->a = lst;
	stacks->b = NULL;
	return (stacks);
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list->binary);
		free(list);
		list = temp;
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		free_list(stacks->a);
	if (stacks->b)
		free_list(stacks->b);
	free(stacks);
}
