/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puiucorina <puiucorina@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:33:44 by puiucorina        #+#    #+#             */
/*   Updated: 2023/08/07 14:04:19 by puiucorina       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	s1_size;

	s1_size = ft_strlen(s1) + 1;
	dup = (char *)malloc(sizeof(*dup) * s1_size);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, s1_size);
	return (dup);
}

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (s_len);
	while (src[i] && (d_len + i < dstsize - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	if (d_len > dstsize)
		return (s_len + dstsize);
	return (s_len + d_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	new_size;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_size = s1_len + s2_len + 1;
	new_str = (char *)malloc(new_size * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, new_size);
	ft_strlcat(new_str, s2, new_size);
	return (new_str);
}
