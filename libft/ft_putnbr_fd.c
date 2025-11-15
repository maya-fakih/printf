/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:12:59 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/08 17:13:28 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_procedure(int nb, int is_negative, char *buffer, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[10];
	int		is_negative;

	is_negative = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	ft_procedure(n, is_negative, buffer, fd);
}

static void	ft_procedure(int nb, int is_negative, char *buffer, int fd)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		buffer[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	if (is_negative)
	{
		write(fd, "-", 1);
	}
	while (i > 0)
	{
		write(fd, &buffer[--i], 1);
	}
}
