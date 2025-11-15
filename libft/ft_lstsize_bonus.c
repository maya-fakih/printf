/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:01:36 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/14 09:01:37 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	count = 0;
	current = lst;
	while (current)
	{
		count++;
		current = current -> next;
	}
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	t_list *testlist = NULL;
// 	ft_lstadd_front(&testlist, ft_lstnew("3"));
// 	ft_lstadd_front(&testlist, ft_lstnew("2"));
// 	ft_lstadd_front(&testlist, ft_lstnew("1"));
// 	printf("%i" , ft_lstsize(testlist));
// }