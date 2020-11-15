/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:40:52 by cisis             #+#    #+#             */
/*   Updated: 2020/11/15 16:19:09 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **line, char **remainder)
{
	char	*nwln;
	char	*tmp;

	nwln = NULL;
	if ((nwln = ft_strchr(*remainder, '\n')))
	{
		*nwln = '\0';
		tmp = *remainder;
		*line = ft_strdup(*remainder);
		*remainder = ft_strdup(++nwln);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*remainder);
		free(*remainder);
		return (0);
	}
	return (1);
}

static int	check_remainder(char **line, char **remainder, int bytes_read)
{
	if (bytes_read == -1)
		return (-1);
	return (get_line(line, remainder));
}

int			get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		buf[BUFFER_SIZE + 1];
	char		*tmpbuf;
	int			bytes_read;

	if (BUFFER_SIZE < 1)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (bytes_read < BUFFER_SIZE)
			buf[bytes_read] = '\0';
		else
			buf[BUFFER_SIZE] = '\0';
		if (!remainder)
			remainder = ft_strdup(buf);
		else
		{
			tmpbuf = remainder;
			remainder = ft_strjoin(remainder, buf);
			free(tmpbuf);
		}
		if (ft_strchr(remainder, '\n'))
			break ;
	}
	return (check_remainder(line, &remainder, bytes_read));
}
