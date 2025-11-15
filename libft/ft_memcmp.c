/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:17:17 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/08 16:07:15 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	if (n == 0)
		return (0);
	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (m1[i] < m2[i])
			return (-1);
		else if (m1[i] > m2[i])
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%i", ft_memcmp("fghjkl", "dfghjkl", 0));
// 	printf("%i", memcmp("fghjkl", "dfghjkl", 0));
// 	//using the memcm from string.h to make sure they
//	//are functioning identically

// }