/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcauza <jalcauza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:09:18 by jalcauza          #+#    #+#             */
/*   Updated: 2021/10/03 17:21:32 by jalcauza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_auxi_printf(const char *str_char, va_list args, unsigned int *counter)
{
	int	result_c; 

	if (*str_char == 'c')
	{
		result_c = va_arg(args, int);
		*counter += write(1, &result_c, 1);
	}
	else if (*str_char == 'u')
		ft_putunbr_printf(va_arg(args, unsigned int), counter);
	else if (*str_char == 'd' || *str_char == 'i')
		ft_putnbr_printf(va_arg(args, int), counter);
	else if (*str_char == 's')
		ft_putstr_printf(va_arg(args, const char *), counter);
	else if (*str_char == 'x' || *str_char == 'X')
		ft_puthex(va_arg(args, unsigned int), *str_char, counter);
	else if (*str_char == 'p')
	{
		ft_putstr_printf("0x", counter);
		ft_puthexp(va_arg(args, unsigned long), counter);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	result;

	if (!str)
		return (-1);
	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				result += write(1, "%", 1);
			else
				ft_auxi_printf(&str[i + 1], args, &result);
			i++;
		}
		else
			result += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}