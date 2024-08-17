/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:15:40 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/17 19:28:05 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void ft_putstr(char *str, int len)
{
	int i = 0;
	while (i < len)
		write(1, &str[i++], 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int main(int ac, char **av)
{
	int	fd;
	int	sz;
	char	buf[4097];

	if(ac == 1)
	{
		ft_putstr("File name missing.\n", ft_strlen("File name missing.\n"));
		return 1;
	}
	if(ac > 2)
	{
		ft_putstr("Too many arguments.\n", ft_strlen("Too many arguments.\n"));
		return 1;
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", ft_strlen("Cannot read file.\n"));
		return 1;
	}
	sz = read(fd, buf, 4096);
	printf("starting size %i\n",sz);
	while (sz > 0)
	{
		ft_putstr(buf, sz);
		sz = read(fd, buf, 4096);
		printf("updated size %i\n",sz);
	}
	close(fd);
}
