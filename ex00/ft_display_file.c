/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:15:40 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/18 12:00:05 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str, int len, int out)
{
	int	i;

	i = 0;
	while (i < len)
		write(out, &str[i++], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	readfile(char *str)
{
	int		fd;
	int		sz;
	char	buf[4097];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", ft_strlen("Cannot read file.\n"), 2);
		return;
	}
	sz = read(fd, buf, 4096);
	while (sz > 0)
	{
		ft_putstr(buf, sz, 2);
		sz = read(fd, buf, 4096);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	int	len;

	len = ft_strlen("Too many arguments.\n");
	if (ac == 1)
	{
		ft_putstr("File name missing.\n", ft_strlen("File name missing.\n"), 2);
		return (1);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n", len, 2);
		return (1);
	}
	readfile(av[1]);
}
