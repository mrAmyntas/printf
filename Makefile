NAME = libftprintf.a
LIBFT_NAME = libft/libft.a
HEADER_FILES =	include/ft_printf.h\
				libft/libft.h
FLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
LIBFT_DIR = libft/
OBJ_DIR = obj/

SRC =	src/conversions1.c\
		src/conversions2.c\
		src/ft_flags.c\
		src/ft_itoa_base.c\
		src/utils.c\
		src/utils2.c\
		src/ft_printf.c

OBJECTS = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
CFLAGS = -Wall -Werror -Wextra

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_NAME)
		ar rcs $@ $^
		ar -q $(LIBFT_NAME) $(OBJECTS)
		cp $(LIBFT_NAME) $(NAME)

$(OBJ_DIR):
	mkdir $@

$(OBJECTS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_FILES)
		$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT_NAME): $(HEADER_FILES) $(LIBFT_DIR)*.c $(LIBFT_DIR)
		make -C libft

clean:
		rm -f obj/*.o
		rm -f libft/*.o

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
