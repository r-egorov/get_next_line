/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:38:53 by cisis             #+#    #+#             */
/*   Updated: 2020/11/11 20:42:38 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s[len])
		len += 1;
	return (len);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = dst;
	s = src;
	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			srclen;

	if (!dst || !src)
		return ((size_t)NULL);
	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			d_i;
	size_t			s_i;

	d_i = 0;
	s_i = 0;
	while (dst[d_i] && d_i < dstsize)
		d_i++;
	while (src[s_i] && ((d_i + s_i + 1) < dstsize))
	{
		dst[d_i + s_i] = src[s_i];
		s_i++;
	}
	if (d_i != dstsize)
		dst[d_i + s_i] = '\0';
	return (d_i + ft_strlen(src));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	unsigned int	len;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	len = s1len + s2len;
	res = (char*)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, s1len + 1);
	ft_strlcat(res, s2, len + 1);
	return (res);
}
