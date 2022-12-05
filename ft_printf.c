/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:10:20 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/05 20:02:36 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_param( char format_specifier, va_list args)
{
	if (format_specifier == '%')
		return (ft_putchar('%'));
	if (format_specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		printed_bytes;

	printed_bytes = 0;
	va_start(args, text);
	while (*text)
	{
		if (*text != '%')
		{
			write(1, text, 1);
			printed_bytes++;
		}
		else
		{
			printed_bytes += get_param(*(text + 1), args);
			text++;
		}
		text++;
	}
	va_end(args);
	return (printed_bytes);
}
