NAME = so_long

RM = rm -f
CC = cc
CFLAGS = -g3 -MMD -MP
LIBFT				= ./libft/libft.a


SRC =	so_long.c \
		handle_error.c \
		init_map.c \
    generate_game.c \
    #   ft_check_input.c \
    #   ft_checks.c \
    #   ft_parse_map.c \
    #   ft_init.c \
    #   ft_init_win.c \
    #   ft_movements.c \
    #   ft_utils.c \
    #   ft_utils2.c \
    #   ft_utils3.c \
    #   ft_end_game.c \

    #   ft_printf.c \
    #   ft_printf_put.c \
    #   ft_printf_utils.c \

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