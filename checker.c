/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:41:25 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 13:46:45 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stacks	*ft_operations(char *line, t_stacks *stacks)
{
	if (line[0] == 's' && (line[1] == 'b' || line[1] == 's' || line[1] == 'a')
		&& line[2] == '\0')
		stacks = ft_swap_mute(stacks, line);
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\0')
		stacks = ft_pa_mute(stacks);
	if (line[0] == 'p' && line[1] == 'b' && line[2] == '\0')
		stacks = ft_pb_mute(stacks);
	if (line[0] == 'r' && (line[1] == 'a' || line[1] == 'b' || line[1] == 'r')
		&& line[2] == '\0')
		stacks = ft_rotate_mute(stacks, line);
	if (line[0] == 'r' && line[1] == 'r'
		&& ((line[2] == 'a' || line[2] == 'b' || line[2] == 'r')
			&& line[3] == '\0'))
		stacks = ft_rotateR_mute(stacks, line);
	return (stacks);
}

int	ft_instruction_check(char *line)
{
	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0
		|| ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "ra") == 0
		|| ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0
		|| ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "pa") == 0
		|| ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0
		|| ft_strcmp(line, "rrr") == 0)
		return (0);
	else
		return (1);
}

int	instruction_loop(t_stacks *stacks, char *line)
{
	if (ft_order(stacks) == 1)
	{
		ft_putstr("OK\n");
		free(stacks);
		return (0);
	}
	line = malloc(sizeof(char));
	if (! line)
		return (0);
	while (line != NULL)
	{
		line = get_next_line(line);
		if (ft_instruction_check(line) == 1 && line[0] != '\0')
		{
			ft_putstr("Error\n");
			free(stacks);
			free(line);
			return (0);
		}
		if (line[0] == '\0')
			break ;
		stacks = ft_operations(line, stacks);
		free(line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*line;

	line = NULL;
	if (argc == 1)
		return (0);
	if (ft_error(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	stacks = stacks_init(argv);
	if (! instruction_loop(stacks, line))
		return (0);
	if (ft_order(stacks) == 1)
	{
		ft_putstr("OK\n");
		free(stacks);
		return (0);
	}
	ft_putstr("KO\n");
	free(stacks);
	return (0);
}
