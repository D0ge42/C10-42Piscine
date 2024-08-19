/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:08:41 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/19 16:41:59 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_file_count(char *filepath)
{
	int	file;
	int	size;
	int	sizetot;
	char	buf[BUFF];

	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		sizetot = 0;
		size = read(file, buf, BUFF);
		while(size != 0)
		{
			sizetot+=size;
			size = read(file, buf, BUFF);
		}
		return (sizetot);
	}
	else
		return (-1);
}

void	ft_file_get(char *filepath, int sizetot, int size)
{
	int	i;
	int	bufsize;
	int	file;
	char	buf[BUFF];

	file = open(filepath, O_RDWR);
	i = 0;
	bufsize = read(file, buf, BUFF);
	while (bufsize != 0 && ((i + 1) * BUFF < sizetot- size))
		i++;
	if (size > sizetot)
		i = -1;
	else
		i = (sizetot - size) % BUFF;
	//Print first part of the needed chunk.
	while (++i < BUFF && i < bufsize)
		ft_putchar(buf[i], 1);
	//Print remaining part of the needed chunk.
	bufsize = read(file, buf, BUFF);
	while(bufsize != 0)
	{
		ft_putstr_buf(buf, bufsize);
		bufsize = read(file, buf, BUFF);
	}
}

