NAME = libft.a

FLAGS = -Wall -Werror -Wextra

IDIR = ./

SDIR = ./

SRC = ft_strdup.c ft_fstrdup.c ft_memalloc.c ft_strchr.c \
ft_strlcat.c ft_strlen.c ft_fstrjoin.c ft_strjoin.c ft_memset.c \
ft_strdel.c ft_strjoin.c ft_strlcpy.c ft_strnew.c ft_putstr.c\
ft_power.c ft_nsqr.c ft_atoi.c\

OBJS = $(SRC:.c=.o)

default: all

all: $(NAME) clean

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)

clean:
	@rm -f *.o
	@rm -f *.gch

fclean: clean
	@rm -fr $(NAME)

re: fclean all
