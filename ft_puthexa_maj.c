/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:56:14 by rmoujan           #+#    #+#             */
/*   Updated: 2021/12/01 19:01:25 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_alpha(int nbr)
{
	if (nbr == 10)
		write(1, "A", 1);
	if (nbr == 11)
		write(1, "B", 1);
	if (nbr == 12)
		write(1, "C", 1);
	if (nbr == 13)
		write(1, "D", 1);
	if (nbr == 14)
		write(1, "E", 1);
	if (nbr == 15)
		write(1, "F", 1);
}

void	ft_puthexa_maj(int n, int *len)
{
	unsigned int	a;

	a = n;
	if (a >= 16)
	{
		ft_puthexa_maj((a / 16), len);
		ft_puthexa_maj((a % 16), len);
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
