/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:44:30 by rmoujan           #+#    #+#             */
/*   Updated: 2021/12/01 18:59:37 by rmoujan          ###   ########.fr       */
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

void	ft_puthexa(int n, int *len)
{
	unsigned int	a;

	a = n;
	if (a >= 16)
	{
		ft_puthexa((a / 16), len);
		ft_puthexa((a % 16), len);
	}
	else if (a >= 10 && a <= 15)
	{
		ft_alpha(a);
		*len = *len + 1;
	}
	else
	{
		ft_putchar((a + '0'), len);
	}
}
