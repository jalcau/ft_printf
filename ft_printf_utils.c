/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcauza <jalcauza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:36:38 by jalcauza          #+#    #+#             */
/*   Updated: 2021/10/03 17:02:57 by jalcauza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(const char *s, unsigned int *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		*counter += write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
	*counter += write(1, &s[i], 1);
		i++;
	}
	return ;
}

void	ft_putnbr_printf(int n, unsigned int *counter)
{
	char	res;

	if (n == -2147483648)
	{
		ft_putnbr_printf(n / 10, counter);
		*counter += write(1, "8", 1);
	}
	else if (n < 0)
	{
		*counter += write(1, "-", 1);
		ft_putnbr_printf(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr_printf(n / 10, counter);
		res = (n % 10) + '0';
		*counter += write(1, &res, 1);
	}
}

void	ft_putunbr_printf(unsigned int n, unsigned int *counter)
{
	char	res;

	if (n > 9)
		ft_putunbr_printf(n / 10, counter);
	res = (n % 10) + '0';
	*counter += write(1, &res, 1);
}

void	ft_puthex(unsigned int hex, char uppercase, unsigned int *counter)
{
	char	*alpha;

	if (uppercase == 'X')
		alpha = "ABCDEF";
	else
		alpha = "abcdef";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putnbr_printf(hex % 16, counter);
		else
			*counter += write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthex(hex / 16, uppercase, counter);
	if (hex % 16 < 10)
		ft_putnbr_printf(hex % 16, counter);
	else
	*counter += write(1, &alpha[hex % 16 - 10], 1);
}	

void	ft_puthexp(unsigned long hex, unsigned int *counter)
{
	char	*alpha;

	alpha = "abcdef";
	if ((hex / 16) == 0)
	{
		if ((hex % 16) < 10)
			ft_putnbr_printf(hex % 16, counter);
		else
			*counter += write(1, &alpha[hex % 16 - 10], 1);
		return ;
	}
	ft_puthexp(hex / 16, counter);
	if (hex % 16 < 10)
		ft_putnbr_printf(hex % 16, counter);
	else
		*counter += write(1, &alpha[hex % 16 - 10], 1);
}
