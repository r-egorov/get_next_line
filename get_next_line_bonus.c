/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:40:52 by cisis             #+#    #+#             */
/*   Updated: 2020/12/01 16:43:57 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_string(char *str)
{
	free(str);
	str = NULL;
}

static int	get_line(char **line, char **remainder)
{
	char	*nwln;
	char	*tmp;

	if ((nwln = ft_strchr(*remainder, '\n')))
	{
		*nwln = '\0';
		tmp = *remainder;
		if (!(*line = ft_strdup(*remainder)) ||
			!(*remainder = ft_strdup(++nwln)))
		{
			free_string(tmp);
			if (*remainder != NULL)
				free_string(*remainder);
			return (-1);
		}
		free_string(tmp);
	}
	else
	{
		if (!(*line = ft_strdup(*remainder)))
			return (-1);
		free_string(*remainder);
		return (0);
	}
	return (1);
}

static int	check_remainder(char **line, char **remainder, int bytes_read)
{
	if ((bytes_read == -1) || !(*remainder))
	{
		if (*remainder != NULL)
			free_string(*remainder);
		return (-1);
	}
	else if (bytes_read == 0 && !(*remainder))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	return (get_line(line, remainder));
}

int			get_next_line(int fd, char **line)
{
	static char	*remainder[4096];
	char		*buf;
	char		*tmpbuf;
	int			bytes_read;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 ||
		(!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char)))))
		return (-1);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (!remainder[fd])
			remainder[fd] = ft_strdup(buf);
		else
		{
			tmpbuf = remainder[fd];
			remainder[fd] = ft_strjoin(remainder[fd], buf);
			free_string(tmpbuf);
		}
		if (ft_strchr(remainder[fd], '\n'))
			break ;
	}
	free_string(buf);
	return (check_remainder(line, &remainder[fd], bytes_read));
}
