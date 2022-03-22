/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:07:15 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:07:17 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	binary_len(int number)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (number == 0)
		return (1);
	num = number;
	while (num > 0)
	{
		count++;
		num /= 2;
	}
	return (count);
}

int	zero_count(int argc)
{
	int	i;

	if (argc <= 7)
		i = 4;
	if (argc > 7 && argc <= 15)
		i = 5;
	if (argc > 15 && argc <= 31)
		i = 6;
	if (argc > 31 && argc <= 47)
		i = 7;
	if (argc > 47 && argc <= 127)
		i = 8;
	if (argc > 127 && argc <= 255)
		i = 9;
	if (argc > 255 && argc <= 511)
		i = 10;
	if (argc > 511 && argc <= 1023)
		i = 11;
	if (argc > 1023 && argc <= 2047)
		i = 12;
	if (argc > 2047 && argc <= 4095)
		i = 13;
	if (argc > 4096 && argc <= 2147483647)
		i = 32;
	return (i);
}

char	*ft_binary_convert_bis(int number, int dif, int size, char *str)
{
	char	*array;

	array = "01";
	str[dif] = '\0';
	if (number == 0)
		str[dif - 1] = '0';
	while (--size > 0)
	{
		str[dif] = array[number % 2];
		number = number / 2;
		dif--;
	}
	if (size == 0)
		str[dif--] = array[number % 2];
	while (dif > -1)
		str[dif--] = '0';
	return (str);
}

char	*ft_binary_convert(int number, int zero, t_stacks *stacks)
{
	char	*str;
	int		size;
	int		dif;

	size = binary_len(number);
	dif = zero - 1;
	str = (char *)malloc(sizeof(char) * (dif + 1));
	if (! str)
	{
		free_stacks(stacks);
		return (NULL);
	}
	str = ft_binary_convert_bis(number, dif, size, str);
	return (str);
}

t_stacks	*binary(t_stacks *stacks, int zero)
{
	t_list	*backup;

	backup = stacks->a;
	while (backup)
	{
		backup->binary = ft_binary_convert(backup->index, zero, stacks);
		backup = backup->next;
	}
	return (stacks);
}
