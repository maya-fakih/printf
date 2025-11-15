/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:05:11 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/15 23:05:12 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_len(int n)
{
	int long	nn;
	int			i;

	nn = n;
	i = 0;
	if (nn < 0)
	{
		write (1, "-", 1);
		nn *= -1;
		i = 1;
	}
	return (ft_putnbr_base_len((unsigned long long)nn, "0123456789") + i);
}
