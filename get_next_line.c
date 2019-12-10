/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 11:57:07 by ztan           #+#    #+#                */
/*   Updated: 2019/12/09 18:57:28 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char temp[BUFFER_SIZE + 1];
	char *ret;
	int val_read;
	int res;

	ret = NULL;
	ret = get_line(ret, temp, fd, val_read);
	if (ret == NULL)
		return (-1);
//	printf("%s", ret);
	*line = ret;
	return (1);
}

char	*get_line(char *ret, char *temp, int fd, int val_read)
{
	char *temp2;
	if (temp[0] == '\0')
		val_read = read(fd, temp, BUFFER_SIZE);
	if (val_read == -1)
		return (NULL);
//	printf("%s", temp);
	if (!ret)
	{
//		printf("%s", temp);
		ret = ft_strdup(temp);
	}
//	printf("%s", ret);
	while (ft_strchr_mk1(temp, '\n') == 0)
	{
//		printf("lol");
		val_read = read(fd, temp, BUFFER_SIZE);
		if (val_read == -1)
			return (NULL);
		if (val_read && ft_strchr_mk1(temp, '\n') == 0)
			ret = ft_strjoin(ret, temp);
//		printf("%s", ret);
	}
//	printf("%s", ret);
	if (ft_strchr_mk1(temp, '\n') != 0)
	{// hieeeeeeer!!!!!!!!
		temp2 = ft_strdup(temp);
		temp2[!ft_strchr_mk1(temp2, '\n')] = '\0';
		ft_strjoin(ret, temp2);
		temp = (temp + ft_strchr_mk1(temp2, '\n'));
	}
//	printf("%s", ret);
	return (ret);
}
