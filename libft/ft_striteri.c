/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:58:18 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/12 00:58:22 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}

// void test(unsigned int i, char *c)
// {
// 	*c += i;
// }
// #include <stdio.h>
// int main()
// {
// 	char s[] = "i wanna sleep";
// 	ft_striteri(s,test);
// 	printf("%s", s);
// }
//meaningful test string is "000000" so you see the iterations working
