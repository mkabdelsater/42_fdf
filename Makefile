# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 13:23:49 by moabdels          #+#    #+#              #
#    Updated: 2024/12/19 12:33:22 by moabdels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= fdf

CC				:= gcc
SRC_DIR			:= src/
OBJ_DIR			:= obj/
CFLAGS			:= -g -O3 -Wall -Werror -Wextra
FSANITIZE		:=
NOFLAGS			:= -g
RM				:= rm -f

INC				:= inc/
LIB				:= lib/
PRINTF_DIR		:= $(LIB)ft_printf/
PRINTF			:= $(PRINTF_DIR)libftprintf.a
MINILIBX_DIR	:= $(LIB)minilibx_linux/
MINILIBX		:= $(MINILIBX_DIR)libmlx.a
MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
LIBS			:= -lXext -lX11 -lm

HEADER			:= -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

RESET_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
WHITE = \033[0;97m
CYAN = \033[0;96m

SRC_FILES		= main

SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS			= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS			= $(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

OBJF			= .cache_exists

all:	makelibs
		@$(MAKE) $(NAME)

makelibs:
	@$(MAKE) -C $(PRINTF_DIR)
	@cd $(MINILIBX_DIR) && ./configure
	@cd ../..
	@$(MAKE) -C $(MINILIBX_DIR)


-include 	${DEPS}
$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(MINILIBXCC)\
				$(LIBS) -o $(NAME)
			@echo "⚙️$(YELLOW) $(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(MINILIBXCC)\
				$(LIBS) -o $(NAME) $(RESET_COLOR)"
			@echo "Project Compiled Successfully!📀"
bonus:
			@$(MAKE) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
				$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)

# when we make printf we should make libft
$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "🟢 ft_printf compiled!"

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "🟢 MiniLibX Compiled!"

clean:
		@make clean -s -C $(PRINTF_DIR)
		@echo "🔵 ft_printf objects and files cleaned!"
		@make clean -C $(MINILIBX_DIR)
		@echo "🔵 MiniLibX object files cleaned"
		$(RM) -r $(OBJ_DIR)
		@echo "🔵 Project Object Files Cleaned!"

# change this to go inside the libraries and run make fclean
fclean:	clean
		$(RM) $(NAME)
		@echo "🔵 Project Executables cleaned!"
		$(RM) $(MINILIBX_DIR)libmlx.a
		@echo "🔵 libmlx.a removed!"
		$(RM) "(LIBFT_DIR)libft.a"

re:		fclean makelibs
		@make
		@echo "🟢 Cleaned and Rebuilt Everything!"

norm:
		@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY: all test bonus lib_clean clean fclean re tclean tre norm
