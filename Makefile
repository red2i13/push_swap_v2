CFLAGS = -Wall -Wextra -Werror -g
FILES =  push_swap.c moves.c get_next_line.c get_next_line_utils.c algo.c
SOURCES = $(addprefix $(SRC_DIR)/, $(FILES))
OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap
CC = cc
LIB = libft
SRC_DIR = src
PRT = printf
LIBFT_DIR = libft/include
INCLUDES = include

all: $(NAME) logo

logo: 
	@echo "██████╗░██╗░░░██╗░██████╗██╗░░██╗░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░"
	@echo "██╔══██╗██║░░░██║██╔════╝██║░░██║██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║░░░██║╚█████╗░███████║╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝"
	@echo "██╔═══╝░██║░░░██║░╚═══██╗██╔══██║░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░"
	@echo "██║░░░░░╚██████╔╝██████╔╝██║░░██║██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░"
	@echo "╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░"

$(NAME): $(OBJECTS) libft/libft.a printf/libftprintf.a 
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDES) -o $@ $^

$(LIB)/libft.a:
	$(MAKE) -C $(LIB) all
$(PRT)/libftprintf.a:
	$(MAKE) -C $(PRT) all

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDES) -c $< -o $@ 
clean:
	rm -f src/*.o
	$(MAKE) -C $(LIB) clean
	$(MAKE) -C $(PRT) clean
fclean: clean
	rm -f push_swap
	$(MAKE) -C $(LIB) fclean
	$(MAKE) -C $(PRT) fclean
re: fclean all

.PHONY: fclean clean re