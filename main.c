/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 17:38:42 by ztan           #+#    #+#                */
/*   Updated: 2019/12/10 09:25:11 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char *line;
	int fd;
	int ret;

	fd = open("testfiles/testfile.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	ret = 1;
//	printf("%d", fd);
//	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		printf("line:[%s]\tstrlen: %zu\tret_val: %d\n", line, ft_strlen(line), ret);
//		free(line);
	}
	close(fd);
	return (0);
}
