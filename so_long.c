#include "so_long.h"

void	extension_check(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	if (s[i] != 'r' || s[i - 1] != 'e' || s[i - 2] != 'b' || s[i - 3] != '.')
		perror_and_exit("Error\n map should be a .ber file");
	return ;
}

void init_map(char **map, t_game *ptr_game)
{
	int		map_fd;
	char	*newline;
	char	*map;

	extension_check(map[1]);
}

void init_struct(t_game *ptr_game)
{
	game->wall = NULL;
	game->coin = NULL;
	game->floor = NULL;
	game->hero = NULL;
	game->exit = NULL;
	game->map = NULL;
	game->img_height = NULL;
	game->img_width = NULL;
	game->map_height = NULL;
	game->map_width = NULL;
	game->mlx_win = NULL;
	game->mlx = NULL;
	game->player_xy = NULL;
	game->move_count = NULL;
	game->error_message = NULL;
	return ;
}

void	init_game(t_game *ptr_game, char **map)
{
	init_struc(ptr_game);
	init_map(map, ptr_game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		perror_exit("unvalid number of arguments");
	init_game(&game, argv[1]);
}