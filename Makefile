# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 13:02:10 by ana-cast          #+#    #+#              #
#    Updated: 2024/01/19 16:54:30 by ana-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

CLIENT = client
SERVER = server
LIBFT = libft/
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = -L ./libft -lft

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRCS_SRV = src/server.c
SRCS_CLT = src/client.c

OBJ_SRV = $(SRCS_SRV:.c=.o)
OBJ_CLT = $(SRCS_CLT:.c=.o)

################################################################################
##                                    COLOURS                                 ##
################################################################################

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW= \033[33m
COLOUR_MAGENTA=\033[35m
COLOUR_TURQUOISE=\033[36m	
COLOUR_END=\033[0m


################################################################################
##                                     RULES                                  ##
################################################################################

all : head $(CLIENT) $(SERVER)

head : 
	@echo "$(COLOUR_MAGENTA)"
	@echo "            _         _  _            _  _    "
	@echo "           (_)       (_)| |          | || |   "
	@echo " _ __ ___   _  _ __   _ | |__   __   | || | __"
	@echo "|  _ \  _ \| ||  _ \ | ||  __| / _ \ | || |/ /"
	@echo "| | | | | || || | | || || |__ | (_) || ||   | "
	@echo "|_| |_| |_||_||_| |_||_| \___| \__\_||_||_|\_\ "
	@echo "                                             "
	@echo "                         42MLG: by ana-cast \n"
	@echo "Proyect: \033[36m minitalk $(COLOUR_MAGENTA)"
	@echo "Commands:\033[36m all clean fclean re $(COLOUR_END)\n"

$(CLIENT) : $(OBJ_CLT)
	@printf " ⏱  Creating libft"
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_CLT) -o $(CLIENT) $(INCLUDE)

$(SERVER) : $(OBJ_SRV)
	@$(CC) $(FLAGS) $(OBJ_SRV) -o $(SERVER) $(INCLUDE)
	@echo "$(COLOUR_GREEN)\r  ✓   Created  $(SERVER), $(CLIENT) and libft $(COLOUR_END)\n"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@printf "\n$(COLOUR_YELLOW) 🗑   Removing objects$(COLOUR_END)"
	@$(RM) $(OBJ_SRV) $(OBJ_CLT)
	@echo "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  objects$(COLOUR_END)"
	@make clean -C $(LIBFT)

fclean: clean
	@printf "$(COLOUR_YELLOW) 🗑   Removing $(CLIENT), $(SERVER) and libft$(COLOUR_END)"
	@$(RM) $(CLIENT) $(SERVER)
	@echo "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  $(CLIENT), $(SERVER) and libft $(COLOUR_END)\n"
	@make fclean -C $(LIBFT)

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

.PHONY: all clean fclean re