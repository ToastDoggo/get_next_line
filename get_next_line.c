/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:30:59 by rehernan          #+#    #+#             */
/*   Updated: 2022/01/14 20:48:16 by rehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_line(char *mover)
{
	char	*moved;

	moved = ft_strchr(mover, '\n');
	if (!moved)
	{
		free(mover);
		return (0);
	}
	if (*(moved + 1))
		moved = ft_strdup(moved + 1);
	else
		moved = NULL;
	free(mover);
	return (moved);
}

char	*get_next_line(int fd)
{
	static char		*whatever;
	char			*dest;
	char			line[BUFFER_SIZE + 1];
	int				size;

	size = read(fd, line, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	line[size] = '\0';
	while (size > 0)
	{
		if (!whatever)
			whatever = ft_strdup(line);
		else
			whatever = ft_strjoin(whatever, line);
		if (ft_strchr(line, '\n'))
			break ;
		size = read(fd, line, BUFFER_SIZE);
		line[size] = '\0';
	}
	dest = ft_substr(whatever, 0, ft_strchr(whatever, '\n') \
		- whatever + 1);
	whatever = move_line(whatever);
	return (dest);
}
