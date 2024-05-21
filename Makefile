CFLAGS = -Wall -Wextra -Werror
FILES =  push_swap.c moves.c moves1.c moves2.c get_next_line.c get_next_line_utils.c algo.c algo1.c algo2.c utils_func.c parse_func.c 
SOURCES = $(addprefix $(SRC_DIR)/, $(FILES))
OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap
BONUS = checker
SOURCES_BONUS = $(addprefix $(SRC_DIR)/, checker.c get_next_line.c get_next_line_utils.c moves.c moves1.c moves2.c checker_utils.c utils_func.c)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
CC = cc
LIB = libft
SRC_DIR = src
PRT = printf
LIBFT_DIR = libft/include
INCLUDES = include

all: $(NAME) logo
bonus: $(BONUS) logo
$(BONUS):$(OBJECTS_BONUS) libft/libft.a printf/libftprintf.a
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDES) -o $(BONUS) $^

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
	rm -f checker
	$(MAKE) -C $(LIB) fclean
	$(MAKE) -C $(PRT) fclean
re: fclean all

.PHONY: fclean clean re