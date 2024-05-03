/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:22:39 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:44:22 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//////////LIBFT/////////
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_join_free_s1(char *s1, char const *s2);
int		ft_printf(const char *text, ...);
//////////LIBFT/////////

void	perror_exit(char *error_message);
void	cleanup(t_game *game);
int		exit_game(t_game *game);
void	init_map(char *map, t_game *game);
void	extension_check(char *s);
void	init_game(t_game *game, char *map);
void	init_p_xy(t_game *game);
void	init_img(t_game *game);
int		game_img_check(t_game *game);
void	init_struct(t_game *game);
void	create_map(char *mapline, t_game *game);
void	free_map_exit(char *mapline, char *newline, char *err);
void	free_map(char **map);
int		map_check(t_game *game);
void	generate_game(t_game *game);
int		path_check(t_game *game);
int		game_input(int keycode, t_game *game);
int		swap_char(char *cur_pos, char *target_pos, t_game *game);
int		map_complete(char **map);
void	set_target(int keycode, int *y, int *x);
int		check_input(int keycode);
int		item_count(char **map);
int		is_closed(char **map);
int		is_rectangle(char **map);
char	*empty_malloc(void);
void	put_img(t_game *game, int x, int y);
int		check_floodfill(char **map);
void	floodfill(char **map, t_xy begin);

#endif