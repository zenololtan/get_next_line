/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 16:37:11 by ztan           #+#    #+#                */
/*   Updated: 2019/12/09 12:04:12 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char temp[BUFFER_SIZE + 1];
	int val_read;
	int check;
	int res;

	
	val_read = read(fd, temp, BUFFER_SIZE);
	if (val_read == -1)
		return (-1);
	printf("val_read: %d\n", val_read);
	while (!ft_strchr(temp, '\n') && val_read != 0);
	{
		val_read = read(fd, temp, BUFFER_SIZE);
		if (val_read == -1)
			return (-1);
	}
	print_line(check, temp, val_read);
	return (1);
}

// opt 1: you read the full file.
// opt 2: you dont read the full sentence.
//if (/*chk_readlen(temp, BUFFER_SIZE) == 1 || */val_read <= BUFFER_SIZE || val_read == 0)
//		check = 1;
//	else

void	print_line(int check, char *temp, int va_read)
{
	
}

// pos:
// 1. hele file lezen en \n tegen komen.
// 2. de hele file lezen en geen \n tegen komen.
// 3. niet de hele file lezen maar wel \n tegen komen.
// 4. niet de hele file lezen en geen \n tegen komen.
//
// aanpak:
// 1. checken of de hele file is gelezen.
//		- als de hele file gelezen is -> 2.
//			- als 2. -> zin tot \n in static char zetten als static char == NULL -> 4. -> 3.
//			- als niet 2. dan hele temp strduppen en 0 returnen.
//		- als niet de hele file is gelezen -> 2.
//			- als 2. -> readen tot \n en geven -> 3.
// 			- 	reread:
//				start - als niet 2. -> opnieuw readen -> 5.
//				1	- als niet 5. -> start.
//				2	- als 5. -> zin tot \n in static char zetten als static char == NULL -> 4. -> 3. 
//			
// 2. checken of er een \n is.
// - ft_strchr(temp, '\n')
// 
// 3. als \n gevonden is -> door lezen tot de volgende \n of eof en in static char opslaan.
//
// 4. static char buf printen
//
// 5. checken voor \n of eof
// - ft_strchr(temp, '\n') || read = 0
//
//
// edge cases?
// 1. na \n eof
//
//
//
//
//