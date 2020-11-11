/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:40:52 by cisis             #+#    #+#             */
/*   Updated: 2020/11/11 18:21:33 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*nl_ptr;
	char		*buf;
	size_t		bytes_read;

	if (BUFFER_SIZE < 1 || !(*line) || 
	!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if (nl_ptr = ft_strchr(remainder, '\n'))
	{
		nl_ptr = '\0'
		*line = ft_strdup(remainder);
		nl_ptr++;
		while (nl_ptr)
			remainder++ = nl_ptr++;
		return (1);
	}
	else if ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
	
	}


}
