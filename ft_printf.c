/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:13:18 by rmoujan           #+#    #+#             */
/*   Updated: 2021/12/01 20:59:09 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process(const char id, va_list args, int *len)
{
	if (id == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (id == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (id == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (id == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (id == 'u')
		ft_putnbru(va_arg(args, int), len);
	else if (id == 'p')
		ft_getadress(va_arg(args, void *), len);
	else if (id == 'x')
		ft_puthexa(va_arg(args, int), len);
	else if (id == 'X')
		ft_puthexa_maj(va_arg(args, int), len);
	else if (id == '%')
	{
		write(1, "%", 1);
		*len = *len + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			process(str[i + 1], args, &len);
			i++;
		}
		else
		{
			ft_putchar(str[i], &len);
		}
		i++;
	}
	va_end(args);
	return (len);
}
