/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:37:44 by ztan           #+#    #+#                */
/*   Updated: 2019/12/10 09:51:17 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *old, char *new)
{
	char	*joined;
	size_t	len_old;
	size_t	len_new;
	size_t	i;
	len_old = ft_strlen(old);
	len_new = ft_strlen(new);
	joined = (char *)malloc(sizeof(char) * (len_old + len_new + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (old[i])
	{
		joined[i] = old[i];
		i++;
	}
	while (*new)
	{
		joined[i] = *new;
		i++;
		new++;
	}
	joined[i] = '\0';
	return (joined);
}


char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int		ft_strchr_mk1(const char *s, int c)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i <= (s_len))
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i <= (s_len))
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
