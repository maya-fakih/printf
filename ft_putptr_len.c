/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:00:25 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/16 10:18:10 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_len(void *ptr)
{
	unsigned long long	address;
	int					count;

	if (!ptr)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long long)ptr;
	count = 0;
	count += ft_putstr_len("0x");
	count += ft_putnbr_base_len(address, "0123456789abcdef");
	return (count);
}
