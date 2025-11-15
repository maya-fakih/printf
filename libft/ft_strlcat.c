/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:10:23 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/08 17:18:25 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen((const char *) dest);
	if (size < destlen + 1)
		return (size + srclen);
	i = destlen;
	j = 0;
	while (src[j] && (j < size - destlen -1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (destlen + srclen);
}
