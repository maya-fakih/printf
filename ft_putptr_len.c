/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:00:25 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/15 23:00:26 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr_len(void *ptr)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	count = 0;
	count += ft_putstr_len("0x");
	count += ft_putnbr_base_len(address, "0123456789abcdef");
	return (count);
}
