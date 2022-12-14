/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:53:55 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/06 15:13:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n /= 16;
	return (len);
}

static void	print_hex(unsigned int n, int arg)
{
	char	hex_base[16];

	if (arg == 1)
		ft_strlcpy(hex_base, "0123456789abcdef", 17);
	else if (arg == 0)
		ft_strlcpy(hex_base, "0123456789ABCDEF", 17);
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 16)
		ft_putchar(hex_base[n % 16]);
	else
	{
		ft_puthex(n / 16, arg);
		ft_putchar(hex_base[n % 16]);
	}
}

int	ft_puthex(unsigned int n, int arg)
{
	print_hex(n, arg);
	return (get_len(n));
}
