/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:42:34 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/15 14:24:50 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (unsigned char) c)
			return (1);
		i++;
	}
	return (0);
}

static int	calclen(char const *s1, char const *set, int	*i)
{
	int	j;

	j = ft_strlen(s1) - 1;
	while (s1[*i] && is_sep(s1[*i], set))
		(*i)++;
	while (is_sep(s1[j], set) && j >= 0)
		j--;
	return (j - *i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	i = 0;
	j = 0;
	len = calclen(s1, set, &i);
	result = NULL;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (s1[i] && j <= len)
		result[j++] = s1[i++];
	result[len] = '\0';
	return (result);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s", ft_strtrim("aaamaya fakihaaaa", "a"));
// }
