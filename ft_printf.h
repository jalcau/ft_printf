/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcauza <jalcauza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:46:49 by jalcauza          #+#    #+#             */
/*   Updated: 2021/10/03 17:21:16 by jalcauza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 
# include <stdarg.h>
# include <unistd.h>

void	ft_putstr_printf(const char *s, unsigned int *counter);
void	ft_putnbr_printf(int n, unsigned int *counter);
void	ft_putunbr_printf(unsigned int n, unsigned int *counter);
void	ft_puthex(unsigned int hex, char uppercase, unsigned int *counter);
void	ft_puthexp(unsigned long hex, unsigned int *counter);
int		ft_printf(const char *str, ...);

#endif