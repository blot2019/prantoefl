#Compiler Options
C_FLAGS =  -Wall -Wextra -Werror -I.
#Filenames
LIBFT_DIR := libft/
NAME :=  libftprintf.a
SRCS := ft_printf.c parser.c print_itoa.c print_int.c print_uint.c\
	print_str.c print_trash.c print_char.c print_float.c print_o.c\
	parser_2.c print_float_2.c print_int_2.c print_o_2.c print_uint_2.c
OBJECTS := $(SRCS:.c=.o)
HEADER = libft/libft.h
all: $(NAME)
$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.a ./
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
$(OBJECTS): %.o: %.c
	gcc $(C_FLAGS) -o $@ -c $<

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -f $(OBJECTS)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)
	/bin/rm -f libft.a
re: fclean all

