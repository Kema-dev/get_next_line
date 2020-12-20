/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:28:58 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/20 23:26:06 by jjourdan         ###   ########lyon.fr   */
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
	size_t	nb_itt;

	i = 0;
	nb_itt = 2;
	fd = open("./gnlTester/files/big_line_no_nl", O_RDONLY);
	line = malloc(sizeof(char **) * nb_itt);
	while (i < nb_itt)
	{
		printf("out=%d ", get_next_line(fd, line));
		printf("line=%s\n", *line);
		printf("i=%ld\n", i);
		free(*line);
		line++;
		i++;
	}
	line -= i;
	free(line);
}
