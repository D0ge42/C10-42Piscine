/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:51:46 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/18 18:53:35 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap(int *a, int *b)
{
	int	c;
	
	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_tail(char *str, int size)
{
	int	i;

	i = 0;
	while(++i < size)
		str[i - 1] = str[i];
}
