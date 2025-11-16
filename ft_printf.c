/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:55:24 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/16 10:17:31 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_len(va_arg(list, int));
	else if (c == 's')
		count = ft_putstr_len(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_len(va_arg(list, int));
	else if (c == 'u')
		count = ft_putnbr_base_len(va_arg(list, unsigned int),
				"0123456789");
	else if (c == 'x')
		count = ft_putnbr_base_len(va_arg(list, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		count = ft_putnbr_base_len(va_arg(list, unsigned int),
				"0123456789ABCDEF");
	else if (c == 'p')
		count = ft_putptr_len(va_arg(list, void *));
	else if (c == '%')
		count = ft_putchar_len('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar_len(s[i]);
			count++;
		}
		else
		{
			i++;
			if (s[i])
				count += type(s[i], list);
		}
		i++;
	}
	va_end(list);
	return (count);
}
