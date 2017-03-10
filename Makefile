NAME = libftprintf.a
SRC = src/ft_printf.o \
      src/get_format.o \
      src/itoa_base.o \
      src/print_address.o \
      src/print_args_type.o \
      src/print_chars.o \
      src/print_decimal.o \
      src/print_hex_uns_oct.o \
      src/print_percent.o \
      src/to_upper_string.o \
      src/form_nbr_string.o \
      src/print_string.o \
      src/form_nbr_string_parts.o
SRC_LFT =	libft/ft_atoi.o \
			libft/ft_bzero.o \
			libft/ft_isalnum.o \
			libft/ft_isalpha.o \
			libft/ft_isascii.o \
			libft/ft_isdigit.o \
			libft/ft_isprint.o \
			libft/ft_itoa.o \
			libft/ft_lstadd.o \
			libft/ft_lstdel.o \
			libft/ft_lstdelone.o \
			libft/ft_lstiter.o \
			libft/ft_lstmap.o \
			libft/ft_lstnew.o \
			libft/ft_memalloc.o \
			libft/ft_memccpy.o \
			libft/ft_memchr.o \
			libft/ft_memcmp.o \
			libft/ft_memcpy.o \
			libft/ft_memdel.o \
			libft/ft_memmove.o \
			libft/ft_memset.o \
			libft/ft_putchar.o \
			libft/ft_putchar_fd.o \
			libft/ft_putendl.o \
			libft/ft_putendl_fd.o \
			libft/ft_putnbr.o \
			libft/ft_putnbr_fd.o \
			libft/ft_putstr.o \
			libft/ft_putstr_fd.o \
			libft/ft_strcat.o \
			libft/ft_strchr.o \
			libft/ft_strclr.o \
			libft/ft_strcmp.o \
			libft/ft_strcpy.o \
			libft/ft_strdel.o \
			libft/ft_strdup.o \
			libft/ft_strequ.o \
			libft/ft_striter.o \
			libft/ft_striteri.o \
			libft/ft_strjoin.o \
			libft/ft_strlcat.o \
			libft/ft_strlen.o \
			libft/ft_strmap.o \
			libft/ft_strmapi.o \
			libft/ft_strncat.o \
			libft/ft_strncmp.o \
			libft/ft_strncpy.o \
			libft/ft_strnequ.o \
			libft/ft_strnew.o \
			libft/ft_strnstr.o \
			libft/ft_strrchr.o \
			libft/ft_strsplit.o \
			libft/ft_strstr.o \
			libft/ft_strsub.o \
			libft/ft_strtrim.o \
			libft/ft_tolower.o \
			libft/ft_toupper.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft -I./
LIBFT = libft.a

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(SRC)
	ar rc  $(NAME) $(SRC_LFT) $(SRC)
	ranlib $(NAME)

%.o : ./%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	make fclean -C ./libft
	/bin/rm -f $(SRC)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
