/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:41:31 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/19 16:17:16 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

// Funzione `two_args`: gestisce i casi in cui l'argomento passato ha il formato `-cN`,
// dove `N` è il numero di byte da leggere dalla fine di un file.
char	**two_args(int *argc, char **argv, int *octet)
{
	int		i;
	char	**args;

	*octet = 0;
	i = 1;
	
	// Ciclo per estrarre il numero `N` dall'argomento `-cN` e memorizzarlo in `*octet`
	while (argv[1][++i] && argv[1][i] >= '0' && argv[1][i] <= '9')
		*octet = *octet * 10 + (argv[1][i] - '0');
	
	// Se ci sono più di 2 argomenti (il primo è il nome del programma e il secondo è `-cN`)
	if (*argc > 2)
	{
		// Alloca spazio per l'array di argomenti, incluso il nome del programma
		args = malloc(sizeof(char*) * *argc);
		args[0] = argv[0]; // Copia il nome del programma come primo argomento
		i = 2;
		
		// Copia gli altri argomenti, escludendo `-cN`
		while (i < *argc)
			args[i] = ft_strdup(argv[i]);
		args[i] = 0; // Aggiunge un terminatore NULL alla fine dell'array
		*argc += 1; // Incrementa il numero di argomenti (ora include il nome del programma)
		return (args); // Ritorna l'array di argomenti modificato
	}

	// Se non ci sono altri argomenti oltre a `-cN`, assume l'input da `stdin`
	args = malloc(sizeof(char*) * 2);
	args[0] = argv[0];
	args[1] = "stdin"; // Indica che l'input proviene da `stdin`
	no_args_stdin(*octet, args); // Chiama la funzione per gestire l'input da `stdin`
	return (0); // Ritorna NULL poiché non ci sono file da leggere
}

// Funzione `three_args`: gestisce i casi in cui l'argomento è nel formato `-c N`,
// con `-c` e `N` separati da uno spazio.
char	**three_args(int argc, char **argv, int octet)
{
	int		i;
	char	**args;

	// Se ci sono più di 3 argomenti (incluso il nome del programma)
	if (argc > 3)
	{
		// Alloca spazio per l'array di argomenti, escludendo `-c` e `N`
		args = malloc(sizeof(char*) * (argc - 1));
		args[0] = argv[0]; // Copia il nome del programma come primo argomento
		i = 2;
		
		// Copia gli altri argomenti, che rappresentano i file da leggere
		while (++i < argc)
			args[i - 2] = ft_strdup(argv[i]);
		args[i - 2] = 0; // Aggiunge un terminatore NULL alla fine dell'array
	}
	else
	{
		// Se non ci sono altri argomenti oltre a `-c` e `N`, assume l'input da `stdin`
		args = malloc(sizeof(char*) * 2);
		args[0] = argv[0];
		args[1] = "stdin"; // Indica che l'input proviene da `stdin`
		no_args_stdin(octet, args); // Chiama la funzione per gestire l'input da `stdin`
		return (0); // Ritorna NULL poiché non ci sono file da leggere
	}
	return (args); // Ritorna l'array di argomenti modificato
}

// Funzione `gest_args`: gestisce e interpreta gli argomenti passati dalla riga di comando,
// decidendo quali altre funzioni chiamare in base agli input.
void	gest_args(int argc, char **argv)
{
	int			octet;
	char		**args;

	// Se non ci sono argomenti o se il primo argomento non è `-c`, chiama `no_args`
	if (argc == 1 || argv[1][0] != '-' || argv[1][1] != 'c')
		no_args(argv);
	
	// Se il primo argomento è `-c`
	else if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		// Se `-c` è l'unico argomento, mostra l'aiuto
		if (argc == 2)
		{
			print_help(argv[0]);
			return ;
		}
		
		// Se `-c` è seguito immediatamente da un numero (senza spazio)
		if (argv[1][2] != '\0')
			args = two_args(&argc, argv, &octet); // Gestisce il caso `-cN`
		
		// Se `-c` è seguito da uno spazio e poi un numero
		else if ((octet = ft_atoi(argv[2])) != -1)
			args = three_args(argc, argv, octet); // Gestisce il caso `-c N`
		
		// Se `N` non è un numero valido, mostra un messaggio di errore
		else
		{
			print_illegal(argv[0], argv[2]);
			return ;
		}
		
		// Se `args` non è NULL, chiama `print_file` per stampare i file
		if (args != 0)
			print_file(argc, args, octet);
	}
}

