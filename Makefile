NAMEC = client
NAMES = server
BONC = client_bonus
BONS = server_bonus
HEADER = minitalk.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
FR = rm -rf
all : $(NAMEC) $(NAMES) 

$(NAMEC) : client.c $(HEADER)
	$(CC) $(CFLAGS) client.c -o client libft.a
$(NAMES) : server.c $(HEADER)
	$(CC) $(CFLAGS) server.c -o server libft.a

bonus : $(BONC) $(BONS)

$(BONC) : client_bonus.c $(HEADER)
	$(CC) $(CFLAGS) client_bonus.c -o client_bonus libft.a
$(BONS) : server_bonus.c $(HEADER)
	$(CC) $(CFLAGS) server_bonus.c -o server_bonus libft.a

clean :
	$(FR) client server

fclean : clean
	$(FR) client_bonus server_bonus

re : fclean all

.PHONY : clean fclean re all