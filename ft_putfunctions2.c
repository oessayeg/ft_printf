/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunctions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:38:34 by oessayeg          #+#    #+#             */
/*   Updated: 2021/12/05 18:47:11 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_puthexa(unsigned int numb, char *base, int *len_string)
{
	if (numb < 16)
		ft_putchar(base[numb], len_string);
	else if (numb >= 16)
	{
		ft_puthexa(numb / 16, base, len_string);
		ft_puthexa(numb % 16, base, len_string);
	}
}

void	ft_putpercent(const char *string, int *index, int *len_string)
{
	ft_putchar('%', len_string);
	(*index)++;
	while (string[*index] == '%' && string[(*index) + 1] == '%')
	{
		ft_putchar('%', len_string);
		*index += 2;
	}
	(*index)--;
}

void	ft_putadd(unsigned long numb, char *base, int *len_string)
{
	if (numb < 16)
		ft_putchar(base[numb], len_string);
	else
	{
		ft_putadd(numb / 16, "0123456789abcdef", len_string);
		ft_putadd(numb % 16, "0123456789abcdef", len_string);
	}
}
