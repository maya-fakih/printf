NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_putnbr_base_len.c \
	   ft_putnbr_len.c \
	   ft_putptr_len.c \
	   ft_putchar_len.c \
	   ft_putstr_len.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re