NAME = fillit

FLAGS = -Wall -Wextra -Werror -pedantic -g

IDIR = ./incs

SDIR = ./srcs

SRC = $(SDIR)/error.c $(SDIR)/main.c $(SDIR)/env.c $(SDIR)/prnt.c $(SDIR)/solve.c $(SDIR)/mnp.c 

LIB = ./libft

default: all

all: $(SRC)
	@gcc $(SRC) -L $(LIB) -I $(LIB) -lft $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(NAME).dSYM
