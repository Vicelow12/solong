#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx_int.h"

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_game
{
	void	*wall;
	void	*box;
	void	*floor;
	void	*hero;
	void	*door;
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
void	cleanup(t_game *game);
int		exit_game(t_game *game);
void 	init_map(char *map, t_game *game);
void	extension_check(char *s);

#endif