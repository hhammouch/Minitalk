


SRC-UTILIS = /utilis/ft_putnbr.c /utilis/ft_putstr.c /utilis/ft_errors.c \
      /utilis/ft_atoi.c

SRC-CLIENT =	client.c
SRC-SERVER =	server.c


CC = CC -Wall -Werror -Wextra

NAME-CLIENT	=	client
NAME-SERVER	=	server





all: $(NAME-CLIENT) $(NAME-SERVER)


$(NAME-CLIENT): $(SRC-CLIENT) $(SRC-UTILIS)
				$(CC) $(SRC-CLIENT) $(SRC-UTILIS) -o $(NAME-CLIENT)
				@echo "Server program was created"

$(NAME-SERVER): $(SRC-SERVER) $(SRC-UTILIS)
				$(CC) $(SRC-SERVER) $(SRC-UTILIS) -o $(NAME-SERVER)
				@echo "(GREEN)Client bonus program was created"



