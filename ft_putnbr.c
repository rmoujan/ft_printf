/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:17 by rmoujan           #+#    #+#             */
/*   Updated: 2021/12/01 15:40:54 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		ft_putchar('-', len);
		a = n * -1;
	}
	if (a >= 10)
	{
		ft_putnbr((a / 10), len);
		ft_putnbr((a % 10), len);
	}
	else
	{
		ft_putchar((a + '0'), len);
	}
}
