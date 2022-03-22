/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:47 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/12 11:27:53 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks	*main_bis(int argc, t_stacks *stacks, char **argv)
{
	t_stacks	*copy;
	int			zero;

	copy = NULL;
	copy = indexing(argv);
	stacks = association(stacks, copy);
	zero = zero_count(argc);
	stacks = binary(stacks, zero);
	stacks = sort_big(stacks, argc, zero);
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	if (ft_error(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	stacks = stacks_init(argv);
	if (ft_order(stacks) == 1)
		return (0);
	if (ft_lstsize(stacks->a) == 2)
		stacks = two(stacks);
	if (ft_lstsize(stacks->a) == 3)
		stacks = three(stacks);
	if (ft_lstsize(stacks->a) == 4 || ft_lstsize(stacks->a) == 5)
		stacks = four_five(stacks);
	if (ft_lstsize(stacks->a) > 5)
		stacks = main_bis(argc, stacks, argv);
	free_stacks(stacks);
	return (0);
}
