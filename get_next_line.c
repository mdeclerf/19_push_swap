/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:06:18 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/09 12:06:20 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_scan(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *buf)
{
	int		i;
	int		j;
	char	*cat;

	i = 0;
	j = 0;
	while (s1 && s1[i] && s1[i] != '\n')
		i++;
	while (buf && buf[j] && buf[j] != '\n')
		j++;
	cat = malloc(i + j + 1);
	if (! cat)
		return (NULL);
	j = 0;
	i = 0;
	while (s1 && s1[j] && s1[j] != '\n')
		cat[i++] = s1[j++];
	while (buf && *buf && *buf != '\n')
		cat[i++] = *buf++;
	cat[i] = 0;
	free(s1);
	return (cat);
}

char	*get_next_line(char *line)
{
	int			rc;
	static char	buf[BUFFER_SIZE + 1];
	int			i;

	rc = 1;
	line = ft_strjoin(NULL, buf);
	if (! line)
		return (NULL);
	while (ft_scan(buf) == -1 && rc && rc != -1)
	{
		rc = read(0, buf, BUFFER_SIZE);
		buf[rc] = '\0';
		line = ft_strjoin(line, buf);
	}
	i = 0;
	if (! buf[0])
		return (line);
	rc = ft_scan(buf) + 1;
	while (buf[i] && buf[rc])
		buf[i++] = buf[rc++];
	buf[i] = 0;
	return (line);
}
