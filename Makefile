CC = cc -Wall -Werror -Wextra

GREEN 	= \033[1;32m
RED		= \033[1;31m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
RC		= \033[0m

NAME_CLIENT = client
NAME_SERVER = server
BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): client.c
	@$(CC) client.c utils.c -o $(NAME_CLIENT)
	@echo "$(GREEN)Client built successfully!✨$(RC)"

$(NAME_SERVER): server.c
	@$(CC) server.c utils.c -o $(NAME_SERVER)
	@echo "$(BLUE)Server built successfully!✨$(RC)"

bonus: $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_CLIENT): client_bonus.c
	@$(CC) client_bonus.c utils.c -o $(BONUS_CLIENT)
	@echo "$(GREEN)Client built successfully!✨$(RC)"

$(BONUS_SERVER): server.c
	@$(CC) server_bonus.c utils.c -o $(BONUS_SERVER)
	@echo "$(BLUE)Server built successfully!✨$(RC)"

clean:
	@rm -f $(NAME_CLIENT) $(NAME_SERVER) $(BONUS_SERVER) $(BONUS_CLIENT)
	@echo "$(YELLOW)Cleaned up!✨$(RC)"
fclean: clean
	@echo "$(RED)All files removed!🗑️$(RC)"

re: fclean all

.PHONY: clean
