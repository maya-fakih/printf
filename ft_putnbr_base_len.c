/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:56:19 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/15 22:56:20 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_putnbr_base_len(unsigned long long n, char *base)
{
	int		count;
	char	digit;
	int		b;

	count = 0;
	b = 0;
	while (base[b])
		b++;
	if (n >= (unsigned long long)b)
		count += ft_putnbr_base_len(n / b, base);
	digit = base[n % b];
	write (1, &digit, 1);
	return (count + 1);
}
