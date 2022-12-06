/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:48:41 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/06 15:30:26 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n /= 16;
	return (len);
}

static void	put_hex(unsigned long long n)
{
	char	hex_base[16];

	ft_strlcpy(hex_base, "0123456789abcdef", 17);
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 16)
		ft_putchar(hex_base[n % 16]);
	else
	{
		put_hex(n / 16);
		ft_putchar(hex_base[n % 16]);
	}
}

int	ft_putaddr(unsigned long long addr)
{
	ft_putstr("0x");
	put_hex(addr);
	return (get_len(addr) + 2);
}
