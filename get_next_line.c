/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:38 by jjourdan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/13 02:06:47 by jjourdan         ###   ########lyon.fr   */
=======
/*   Updated: 2020/12/02 18:44:26 by jjourdan         ###   ########lyon.fr   */
>>>>>>> 18d4a2a85d12d8d47d3bd2a34410674d80662fb2
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
	while (--i >= 0)
		out[i] = save[i];
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
<<<<<<< HEAD
			free(save); // ! si fd < 0 direct free un non malloc
=======
			free(buf);
			if (save)
				free(save);
>>>>>>> 18d4a2a85d12d8d47d3bd2a34410674d80662fb2
			return (-1);
		}
		buf[head] = 0;
		save = ft_strjoin(save, buf);
	}
	printf("buf=%s\n", buf); // ! quand atteint EOF erreur memoire
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
