NAME = so_long

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP
LIBFT				= ./libft/libft.a


SRC =	so_long.c \
		handle_error.c \
		init_map.c \
    generate_game.c \
    map_check.c\
    flood_fill.c\
    game_input.c\
    init_game.c\

OBJS = $(SRC:%.c=%.o)
DEPS = $(OBJS:%.o=%.d)

all : $(NAME)

$(LIBFT): FORCE
					make -C ./libft

FORCE :

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

-include $(DEPS)

$(NAME) : $(OBJS) $(LIBFT)
	cd minilibx-linux && $(MAKE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lminilibx-linux -l:libmlx.a -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	cd minilibx-linux && $(MAKE) clean
	$(RM) $(OBJS) $(DEPS)
	make clean -C ./libft

fclean : clean
	cd minilibx-linux && $(MAKE) clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re