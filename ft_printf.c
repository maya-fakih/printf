#include <stdarg.h>
#include "libft.h"

static int type(char c, va_list list)
{
    int count;

    count = 0;
    if (c == 'c')
		count = ft_putchar_len(va_arg(list, int), 1); 
    else if (c == 's')
        count = ft_putstr_len(va_arg(list, char *)); 
    else if (c == 'd' || c == 'i')
        count = ft_putnbr_len(va_arg(list, int));
    else if (c == 'u')
        count = ft_putunsigned_len(va_arg(list, unsigned int)); 
    else if (c == 'x')
        count = ft_puthex_len(va_arg(list, unsigned int), 0); // 0 for lowercase
    else if (c == 'X')
        count = ft_puthex_len(va_arg(list, unsigned int), 1); // 1 for uppercase
    else if (c == 'p')
        count = ft_putptr_len(va_arg(list, void *));
    else if (c == '%')
        count = ft_putchar_len('%', 1);
    
    return (count);
}
int	ft_printf(const char *s, ...)
{
	va_list list;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] != '%')
		{	
			ft_putchar_fd(s[i++], 1);
			count++;
		}
		else
		{	
			i++;
			
		}
	}
	
	va_end(list);
}
