/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcauza <jalcauza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:30:14 by jalcauza          #+#    #+#             */
/*   Updated: 2021/10/03 16:37:08 by jalcauza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include <stdio.h>

int	main()
{
	int	i=42;
	char *str="El texto";
	void	*ptr;
	
	ptr = str;
	printf("TEXTO REAL:\n");
	printf("Porcentaje: %%\nCaracter: %c\nString: %s\nDecimal: %d\n",i,str,i); //Puntero: %p
	printf("\n\n---------------------\n\n");
	printf("TEXTO FT:\n");
	ft_printf("Porcentaje: %%\nCaracter: %c\nString: %s\nDecimal: %d\n",i,str,i); //\nPuntero: %p
	return (0);
}