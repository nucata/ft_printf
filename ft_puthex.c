/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:53:55 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/06 13:07:59 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	slen = -1;
	while (src[++slen])
		;
	if (dstsize == 0)
		return (slen);
	i = -1;
	while (src[++i] && i < dstsize - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (slen);
}

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n && ++len)
		n /= 16;
	return (len);
}

static void	print_hex(int n)
{
	char	hex_base[16];

	ft_strlcpy(hex_base, "0123456789abcdef", 17);
	if (n < 16)
	{
		ft_putchar(hex_base[n % 16]);
	}
	else
	{
		ft_putnbr(n / 16);
		ft_putchar(hex_base[n % 16]);
	}
}

unsigned int	ft_puthex(int n)
{
	print_hex(n);
	return (get_len(n));
}
