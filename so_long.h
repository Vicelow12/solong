#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_game
{
	void	*wall;
	void	*coin;
	void	*floor;
	void	*hero;
	void	*exit;
	char	**map;
	char	**map_double;
	int		img_height;
	int		img_width;
	size_t	map_height;
	size_t	map_width;
	void	*mlx_win;
	void	*mlx;
	t_xy	player_xy;
	int		move_count;
	char	*error_message;
}	t_game;

void	perror_exit(char *error_message);

#endif