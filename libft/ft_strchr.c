/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:43:00 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/08 17:16:43 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
//  int main()
//  {
// 	char s1[100] = "hello my name is maya how are you miled";
// 	printf("%s", (char *) strchr(s1, 'm'));
//  }
//remember you should always cast ints to unsigned char
//to compare with s[i]