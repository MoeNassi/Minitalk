NAME = client
NAME1 = server

CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = client.c
SRC1 = server.c
OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)

all : $(NAME) $(NAME1)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) libft.a

$(NAME1) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1) libft.a

clean :
	rm -rf $(OBJ) $(OBJ1)

fclean : clean
	rm -rf $(NAME) $(NAME1)

re : fclean all