/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:34:57 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/15 18:42:59 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_base_len(unsigned long long n, char *base);
int		ft_putchar_len(char c);
int		ft_putstr_len(char *s);
int		ft_putnbr_len(int n);
int		ft_putptr_len(void *p);

#endif