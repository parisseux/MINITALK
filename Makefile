# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 13:52:16 by parissachat       #+#    #+#              #
#    Updated: 2024/12/03 15:44:14 by parissachat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBDIR = libraries
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(LIBDIR)/ft_printf -g
RM = rm -f

SRCDIR = src
OBJDIR = obj

FT_PRINTF = $(LIBDIR)/ft_printf/libftprintf.a

FILES_SERVER = server.c
FILES_CLIENT = client.c 
FILES_SERVER_BONUS = server_bonus.c
FILES_CLIENT_BONUS = client_bonus.c 

OBJ_SERVER = $(addprefix $(OBJDIR)/, $(FILES_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(OBJDIR)/, $(FILES_CLIENT:.c=.o))
OBJ_SERVER_BONUS = $(addprefix $(OBJDIR)/, $(FILES_SERVER_BONUS:.c=.o))
OBJ_CLIENT_BONUS = $(addprefix $(OBJDIR)/, $(FILES_CLIENT_BONUS:.c=.o))

SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus
	
all: $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

$(SERVER_NAME): $(OBJ_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) -o $(SERVER_NAME)

$(CLIENT_NAME): $(OBJ_CLIENT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) -o $(CLIENT_NAME)

$(SERVER_NAME_BONUS): $(OBJ_SERVER_BONUS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(FT_PRINTF) -o $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): $(OBJ_CLIENT_BONUS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(FT_PRINTF) -o $(CLIENT_NAME_BONUS)

$(FT_PRINTF):
	@make -C $(LIBDIR)/ft_printf
		
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)  # Ensure obj/ directory exists
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	@rmdir $(OBJDIR) 2>/dev/null || true  # Remove obj/ only if empty
	@make -C $(LIBDIR)/ft_printf clean

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
	@make -C $(LIBDIR)/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re