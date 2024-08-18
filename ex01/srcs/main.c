/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:50:02 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/18 17:12:26 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		no_args(av);
	else
	{
		i = 0;
		while (++i < ac)
		{
			if (ft_file_read(av[i]) == 0)
			{
				ft_putstr(basename(av[0]), 2);
				ft_putstr(": ", 2);
				ft_putstr(av[i], 2);
				ft_putstr(": ", 2);
				ft_putstr(strerror(errno),2);
				ft_putchar('\n', 2);
			}
		}
	}
}
