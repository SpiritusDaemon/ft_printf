NAME = libftprintf.a


FUNC = ft_printf.c \
	ft_printf_utils.c \
	ft_printf_more_utils.c \



CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(FUNC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

		ar -rcs $@ $^

run:
	$(CC) $(FLAGS) $(NAME) -o main
	./main

clean:
	rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
		rm -rf main

re:	clean

	rm -rf $(NAME)
	make all
	make clean

r:
	make re && clear && ./main
	
bonus:

.PHONY: all clean run fclean re bonus
