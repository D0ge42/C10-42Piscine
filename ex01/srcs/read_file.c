/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:43:44 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/18 17:23:51 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_file_read(char *filepath)
{
	int		file;
	int		size;
	char	buf[BUFF];

	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		size = read(file, buf, BUFF);
		while (size > 0)
		{
			ft_putstr_buf(buf, size);
			size = read(file, buf, BUFF);
		}
		return (1);
	}
	else
		return (0);
}
