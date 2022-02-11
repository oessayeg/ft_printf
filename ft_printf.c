/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:13 by oessayeg          #+#    #+#             */
/*   Updated: 2021/12/05 19:00:04 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_format(const char *string, int *index, int *len, va_list pt)
{
	(*index)++;
	if (string[*index] == 'c')
		ft_putchar(va_arg(pt, int), len);
	else if (string[*index] == 's')
		ft_putstring(va_arg(pt, char *), len);
	else if (string[*index] == 'd' || string[*index] == 'i')
		ft_putint(va_arg(pt, int), len);
	else if (string[*index] == 'u')
		ft_putunsigned(va_arg(pt, unsigned int), len);
	else if (string[*index] == 'x')
		ft_puthexa(va_arg(pt, unsigned int), "0123456789abcdef", len);
	else if (string[*index] == 'X')
		ft_puthexa(va_arg(pt, unsigned int), "0123456789ABCDEF", len);
	else if (string[*index] == 'p')
	{
		write(1, "0x", 2);
		(*len) += 2;
		ft_putadd(va_arg(pt, unsigned long), "0123456789abcdef", len);
	}
	else if (string[*index] == '%')
		ft_putpercent(string, index, len);
	(*index)++;
}

int	ft_printf(const char *format, ...)
{
	int		compteur;
	int		len;
	va_list	pointer;

	va_start(pointer, format);
	len = 0;
	compteur = 0;
	while (1)
	{
		if (format[compteur] == '%')
			print_format(format, &compteur, &len, pointer);
		if (format[compteur] == '\0')
			break ;
		if (format[compteur] != '%')
		{	
			ft_putchar(format[compteur], &len);
			compteur++;
		}
	}
	va_end(pointer);
	return (len);
}
