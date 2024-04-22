# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 13:02:10 by ana-cast          #+#    #+#              #
#    Updated: 2024/04/22 16:27:00 by ana-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

CLIENT = client
CLIENT_BON = client_bonus
SERVER = server
SERVER_BON = server_bonus
LIBFT = lib/libft/
MINITALK = include/
CC_FLAGS = gcc -Wall -Wextra -Werror
RM = rm -f
INCLUDE = -L ./lib/libft -lft

DEPS = -I include -I $(LIBFT)/include

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRCS_SRV = src/server.c
SRCS_CLT = src/client.c

B_SRC_SV = src/server_bonus.c
B_SRC_CL = src/client_bonus.c

OBJ_SRV = $(SRCS_SRV:.c=.o)
OBJ_CLT = $(SRCS_CLT:.c=.o)

B_OBJ_SR = $(B_SRC_SV:.c=.o)
B_OBJ_CL = $(B_SRC_CL:.c=.o)

################################################################################
##                                    COLOURS                                 ##
################################################################################

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[33m
MAGENTA=\033[35m
TURQUOISE=\033[36m	
END=\033[0m

################################################################################
##                                     RULES                                  ##
################################################################################

all : head libft $(CLIENT) $(SERVER)

bonus : head libft $(CLIENT_BON) $(SERVER_BON)

head : 
	@echo "$(MAGENTA)"
	@echo "\t            _         _  _           _  _     "
	@echo "\t           (_)       (_)| |         | || |    "
	@echo "\t _ __ ___   _  _ __   _ | |_    ___ | || | __ "
	@echo "\t|  _ \ _ \ | || '_ \ | || __| / _  || || |/ / "
	@echo "\t| | | | | || || | | || || |_ | (_| || ||   <  "
	@echo "\t|_| |_| |_||_||_| |_||_| \__| \__,_||_||_|\_\ "
	@echo ""
	@echo "\t        42MLG: by ana-cast"
	@echo "\tProyect: \033[36m so_long $(MAGENTA)"
	@echo "\tCommands:\033[36m all clean fclean re $(END)\n"

libft :
	@make -C $(LIBFT)

$(CLIENT) : line $(OBJ_CLT)
	@echo "✦ ---------------------- ✦$(END)"
	@$(CC_FLAGS) $(OBJ_CLT) $(INCLUDE) -o $(CLIENT)

$(SERVER) : line $(OBJ_SRV)
	@echo "✦ ---------------------- ✦$(END)"
	@$(CC_FLAGS) $(OBJ_SRV) $(INCLUDE) -o $(SERVER)

$(CLIENT_BON) : line $(B_OBJ_CL)
	@echo "✦ ---------------------- ✦$(END)"
	@$(CC_FLAGS) $(B_OBJ_CL) $(INCLUDE) -o $(CLIENT_BON)

$(SERVER_BON) : line $(B_OBJ_SR)
	@echo "✦ ---------------------- ✦$(END)"
	@$(CC_FLAGS) $(B_OBJ_SR) $(INCLUDE) -o $(SERVER_BON)

%.o : %.c $(MINITALK)
	@$(CC_FLAGS) -c $< -o $@ $(DEPS)
	@echo "$(GREEN)  ✓ Compiled: $(notdir $<)"

line :
	@echo "$(GREEN) $(BOLD)"
	@echo "    COMPILING MINITALK...$(END) $(GREEN)"
	@echo "✦ ---------------------- ✦"

clean :
	@printf "\n$(YELLOW) 🗑   Removing objects$(END)"
	@$(RM) $(OBJ_SRV) $(OBJ_CLT) $(B_OBJ_SR) $(B_OBJ_CL)
	@echo "$(GREEN)\r  ✓  $(RED)Removed  objects from $(CLIENT) and $(SERVER) $(END)"
	@make clean -C $(LIBFT)

fclean: clean
	@printf "$(YELLOW) 🗑   Removing $(CLIENT) and $(SERVER) $(END)"
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BON) $(SERVER_BON)
	@make fclean -C $(LIBFT)
	@echo "$(GREEN)\r  ✓  $(RED)Removed  $(CLIENT) and $(SERVER) $(END)\n"

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

.PHONY: all bonus clean fclean re