/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:40:52 by cisis             #+#    #+#             */
/*   Updated: 2020/11/11 20:37:08 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	char		*tmpbuf;
	size_t		bytes_read;

	if (BUFFER_SIZE < 1 || !(*line) || 
	!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((bytes_read = read(fd, buf, BUF_SIZE) > 0))
	{
		buf[BUF_SIZE] = '\0';
		if (!remainder)
			remainder = ft_strdup(buf);
		else
		{
			tmpbuf = remainder;
			remainder = ft_strjoin(remainder, buf);
			free(tmpbuf);
		}
		if (ft_strchr(remainder, '\n'))
			break;
	}
	free(buf);
	return ();
}
