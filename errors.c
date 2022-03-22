/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:05:56 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:05:58 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	check_double(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!(ft_strcmp(argv[i], argv[j])))
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

int	check_digit(char **argv, int i)
{
	int	j;

	j = 0;
	while (argv[i][j])
	{
		if (argv[i][j] == '-' && j == 0)
			j ++;
		if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			return (1);
		j ++;
	}
	return (0);
}

int	ft_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (check_double(argv) == 1)
		return (1);
	while (i < argc)
	{
		if ((ft_atoi(argv[i])) > 2147483647 || (ft_atoi(argv[i])) < -2147483648)
			return (1);
		j = 0;
		if (check_digit(argv, i) == 1)
			return (1);
		i ++;
	}
	return (0);
}
