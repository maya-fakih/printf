/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:43:28 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/08 17:07:07 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*d;
	unsigned const char		*s;

	i = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *) d);
}

// #include <stdio.h>
// int main()
// {
// 	char h[] = "hii";
// 	char dest[] = "";
// 	printf("%s",(char *) 	ft_memcpy(dest, h, 2));
// }