NAME = fillit

FLAGS = -Wall -Wextra -Werror -g 

IDIR = inc

SDIR = src

SRC = $(SDIR)/error.c $(SDIR)/main.c $(SDIR)/env.c $(SDIR)/prnt.c $(SDIR)/solve_sh.c $(SDIR)/mnp.c $(SDIR)/solve_ll.c

LIB = ./libft

default: all

all: $(SRC)
	@gcc $(SRC) -L $(IDIR)/$(LIB) -I $(IDIR)/$(LIB) -I $(IDIR) -lft $(FLAGS) -o $(NAME)

clean:
	@rm -rf $(NAME).dSYM

fclean: clean
	@rm -fr $(NAME)

re: fclean all
