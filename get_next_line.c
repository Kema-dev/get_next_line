/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:38 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/01 21:15:37 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_save(char *save)
{
	size_t	i;
	size_t	j;
	char	*out;

	i = 0;
	j = 0;
	while ((save[i] != '\n') && (save[i] != 0))
	{
		if (save[i] == 0)
			return (NULL);
		i++;
	}
	i++;
	if (!(out = malloc(sizeof(char) * (ft_strlen(&save[i]) + 1))))
		return (NULL);
	while (save[i] != 0)
	{
		out[j] = save[i];
		i++;
		j++;
	}
	out[j] = 0;
	return (out);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*out;

	i = 0;
	while ((save[i] != '\n') && (save[i] != 0))
		i++;
	if (!(out = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	out[i] = 0;
	i--;
	while (i >= 0)
	{
		out[i] = save[i];
		i--;
	}
	return (out);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			head;

	head = 1;
	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0) || (!(buf = \
					malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((ft_new_line(save) != 0) && (head != 0))
	{
		if ((head = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(buf);
			return (-1);
		}
		buf[BUFFER_SIZE] = 0;
		save = ft_strjoin(save, buf);
	}
	free(buf);
	*line = ft_get_line(save);
	save = ft_get_save(save);
	if (head == 0)
	{
		free(save);
		return (0);
	}
	return (1);
}
