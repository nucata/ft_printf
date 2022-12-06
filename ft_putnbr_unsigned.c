/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:16:20 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/06 13:21:24 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n && ++len)
		n /= 10;
	return (len);
}

static void	print_num(unsigned int n)
{
	if (n < 10)
		ft_putchar(n % 10 + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

int	ft_putnbr_unsigned(unsigned int n)
{
	print_num(n);
	return (get_len(n));
}
