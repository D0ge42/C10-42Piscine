/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:50:35 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/18 17:15:31 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	no_args(char **av)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
	{
		if (errno == 0)
			ft_putchar(buf, 1);
		else
		{
			ft_putstr(basename(av[0]), 2);
			ft_putstr(": stdin: ", 2);
			ft_putstr(strerror(errno), 2);
			ft_putchar('\n', 2);
			return;
		}
	}
}
