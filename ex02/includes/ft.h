/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:27:25 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/19 16:33:45 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFF 30000

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>

void	ft_putchar(char c, int out);
void	ft_swap(int *a, int *b);
void	ft_swap_tail(char *str, int size);
void	ft_putstr(char *str, int out);
void	ft_putstr_buf(char *str, int size);
void	ft_putstr_headfile(char *filename);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_file_count(char *filepath);
void	ft_file_get(char *filepath, int sizetot, int size);
void	ft_file_std(void);
void	no_args(char **argv);
void	no_args_stdin(int size, char **args);
void	gest_args(int argc, char **argv);
int		ft_atoi(char *str);
char	*ft_strdup(char *src);
void	print_file(int argc, char **args, int octet);
void	print_illegal(char *name, char *obj);
void	print_error(char **args, int i);
void	print_help(char *name);

#endif

