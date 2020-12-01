/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:28:58 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/01 21:19:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	**line;
	int		fd;
	size_t	i;

	i = 0;
	fd = open("normal.txt", O_RDONLY);
	line = malloc(sizeof(char **) * 500);
	while (i < 500)
	{
		printf("out=%d ", get_next_line(fd, line));
		printf("line=%s\n", *line);
		line++;
		i++;
	}
	line -= i;
	free(line);
}
