/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:54:51 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/08 17:55:11 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	c = malloc((i + 1) * (sizeof(char)));
	if (c == 0)
		return (NULL);
	while (j <= i)
	{
		c[j] = src[j];
		j++;
	}
	return (c);
}
//#include <stdio.h>
// int main()
// {
// 	char s[] = "hunger is hunger :)";
// 	char *d;
// 	d = ft_strdup(s);
// 	printf("%s", d);
// }