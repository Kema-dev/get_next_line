/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:50 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/01 21:13:43 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!src)
		return ((char *)dest);
	while (dest[i] != 0)
		i++;
	while (src[j] != 0)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	tot_len;
	char	*out;

	if (!s2)
		return ((char *)s1);
	tot_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(out = malloc(sizeof(char) * (tot_len + 1))))
		return (NULL);
	out = ft_memset(out, 0, tot_len);
	ft_strcat(out, (char *)s1);
	ft_strcat(out, (char *)s2);
	out[tot_len] = 0;
	free(s1);
	return (out);
}

int		ft_new_line(char *save)
{
	size_t i;

	i = 0;
	if (!save)
		return (-1);
	while (save[i] != 0)
	{
		if (save[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}
