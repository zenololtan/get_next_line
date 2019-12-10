/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:37:27 by ztan           #+#    #+#                */
/*   Updated: 2019/12/10 10:23:10 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 32
# endif

typedef struct	s_list
{
	char	*buffer;
	char	*pointer;
	int		head;
	int		tail;
	int		flag;
}				t_buff;


int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_isascii(int c);
int		chk_readlen(char *temp, int BUFF_SIZE);
int		ft_strchr_mk1(const char *s, int c);
char	*get_line(char *ret, char *temp, int fd, int val_read);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *old, char *new);


#endif
