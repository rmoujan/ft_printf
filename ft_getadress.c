/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:43:17 by rmoujan           #+#    #+#             */
/*   Updated: 2021/12/01 18:56:34 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_alpha(int nbr)
{
	if (nbr == 10)
		write(1, "a", 1);
	if (nbr == 11)
		write(1, "b", 1);
	if (nbr == 12)
		write(1, "c", 1);
	if (nbr == 13)
		write(1, "d", 1);
	if (nbr == 14)
		write(1, "e", 1);
	if (nbr == 15)
		write(1, "f", 1);
}

static void	ft_hex(unsigned long long n, int *len)
{
	if (n >= 16)
	{
		ft_hex((n / 16), len);
		ft_hex((n % 16), len);
	}
	else if (n >= 10 && n <= 15)
	{
		ft_alpha(n);
		*len = *len + 1;
	}
	else
	{
		ft_putchar((n + '0'), len);
	}
}

void	ft_getadress(void *p, int *len)
{
	unsigned long long	ad;

	ad = (unsigned long long)p;
	write(1, "0", 1);
	write(1, "x", 1);
	*len = *len + 2;
	ft_hex(ad, len);
}
