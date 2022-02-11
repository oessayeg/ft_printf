/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:02:42 by oessayeg          #+#    #+#             */
/*   Updated: 2021/12/03 18:25:03 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

# include <unistd.h>

# include <stdarg.h>

void	ft_putchar(char c, int *len_string);
void	ft_putstring(char *st, int *len_string);
void	ft_putint(int nb, int *len_string);
void	ft_putunsigned(unsigned int nb, int *len_string);
void	ft_puthexa(unsigned int numb, char *base, int *len_string);
void	ft_putpercent(const char *string, int *index, int *len_string);
void	ft_putadd(unsigned long numb, char *base, int *len_string);
int		ft_printf(const char *format, ...);
#endif
