#**************************************************************************** #
# #
# :: : :: :: :: ::#
#Makefile : + : : + : : + : #
#+ : + + : + + : + #
#By : mjadid < mjadid @student .42.fr> + # + + : ++# + #
#+ #+ #+ #+ #+ #+ + #+ #
#Created : 2024 / 06 / 28 01 : 12 : 06 by mjadid # + # # + # #
#Updated : 2024 / 06 / 28 02 : 21 : 54 by mjadid## # ########.fr #
# #
#**************************************************************************** #

INC = minitalk.h
INC_BONUS = minitalk.h

CFLAGS = -Wall -Wextra -Werror

all : server client

bonus : server_bonus client_bonus

server : server.c  $(INC) 
		cc $(CFLAGS) server.c -o server

client : client.c $(INC)
		cc $(CFLAGS) client.c -o client

server_bonus : server_bonus.c $(INC_BONUS)
		cc $(CFLAGS) server_bonus.c -o server_bonus

client_bonus : client_bonus.c $(INC_BONUS)
		cc $(CFLAGS) client_bonus.c -o client_bonus

clean :

fclean : clean
		rm -rf server server_bonus client client_bonus

re : fclean all