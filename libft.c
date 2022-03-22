/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:26 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:06:28 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (count < ft_strlen(str))
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return (s1[0] - s2[0]);
	else
	{
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			else
				i++;
		}
		return (0);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
