CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror -Wno-unused-variable -Lmlx_linux \
					 -lmlx_Linux -L/usr/lib-Imlx_linux -lXext -lX11 -lm \
					 -lz -o
NAME			= my_fdf
SRC				= my_fdf.c mlx_utils.c
OBJ				= $(SRC:%.c=%.o)
RM				= rm -rf

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

