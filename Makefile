NAME = fillit

FLAGS = -Wall -Wextra -Werror -pedantic -g

IDIR = ./incs

SDIR = ./srcs

SRC = error.c main.c env.c prnt.c solve_sh.c mnp.c solve_ll.c

LIB = ./libft

default: all

all: $(SRC)
	@gcc $(SRC) -L $(LIB) -I $(LIB) -lft $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(NAME).dSYM
