#include "so_long.h"

void	free_map_exit(char *mapline, char *newline, char *err)
{
	free(mapline);
	free(newline);
	perror_exit(err);
}

void	extension_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	if (s[i] != 'r' || s[i - 1] != 'e' || s[i - 2] != 'b' || s[i - 3] != '.')
		perror_exit("Error\n map should be a .ber file");
	return ;
}

void	create_map(char *mapline, t_game *game)
{
	// if (!map_array)
	// 	perror_and_exit("Error\nfailed to get map");
	game->map = ft_split(mapline, '\n');
	// game->map_double = ft_split(map_array, '\n');
	free(mapline);
	if (!game->map /*|| !game->map_double*/)
	{
		game->error_message = "Error\nsplit failed";
		exit_game(game);
	}
}
void	init_map(char *map, t_game *game)
{
	int		map_fd;
	char	*newline;
	char	*mapline;

	extension_check(map);
	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
		perror_exit("Error\nfailed to open map fd");
	mapline = malloc(sizeof(char));
	if (!mapline)
		perror_exit("Error\nempty malloc failed");
	mapline[0] = '\0';
	newline = get_next_line(map_fd);
	if (newline)
		game->map_width = ft_strlen(newline) - 1;
	game->map_height = 0;
	while (newline)
	{
		mapline = ft_join_free_s1(mapline, newline);
		if(!mapline)
			free_map_exit(mapline, newline, "Error\nft_join_free_s1");
		free(newline);
		newline = get_next_line(map_fd);
		game->map_height += 1;
		printf("mapheight : %zu", game->map_height );
	}
	if (close(map_fd) == -1)
		free_map_exit(mapline, newline, "Error\nclose mapfd");
	create_map(mapline, game);
} 

