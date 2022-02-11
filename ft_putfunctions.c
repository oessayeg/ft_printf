/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:02:34 by oessayeg          #+#    #+#             */
/*   Updated: 2021/12/05 18:48:16 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar(char c, int *len_string)
{
	write(1, &c, 1);
	(*len_string)++;
}

int	ft_strlen(char *st)
{
	int	l;

	l = 0;
	while (st[l] != '\0')
		l++;
	return (l);
}

void	ft_putstring(char *st, int *len_string)
{
	int	j;

	j = 0;
	if (st == NULL)
	{
		write(1, "(null)", 6);
		(*len_string) += 6;
		return ;
	}
	while (st[j] != '\0')
	{
		ft_putchar(st[j], len_string);
		j++;
	}
}

void	ft_putunsigned(unsigned int nb, int *len_string)
{
	if (nb < 10)
		ft_putchar(nb + '0', len_string);
	else if (nb >= 10)
	{
		ft_putunsigned(nb / 10, len_string);
		ft_putunsigned(nb % 10, len_string);
	}
}

void	ft_putint(int nb, int *len_string)
{
	if (nb == -2147483648)
		ft_putstring("-2147483648", len_string);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-', len_string);
			nb *= -1;
		}
		if (nb < 10)
			ft_putchar(nb + '0', len_string);
		else if (nb >= 10)
		{
			ft_putint(nb / 10, len_string);
			ft_putint(nb % 10, len_string);
		}
	}
}
