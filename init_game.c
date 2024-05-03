/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:35:43 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:44:03 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->wall = NULL;
	game->box = NULL;
	game->floor = NULL;
	game->hero = NULL;
	game->door = NULL;
	game->map = NULL;
	game->map_double = NULL;
	game->mlx_win = NULL;
	game->mlx = NULL;
	game->move_count = 0;
	game->error_message = NULL;
	return ;
}

int	game_img_check(t_game *game)
{
	int	check;

	check = 1;
	if (!(game->wall))
		check = 0;
	if (!(game->box))
		check = 0;
	if (!(game->floor))
		check = 0;
	if (!(game->hero))
		check = 0;
	if (!(game->door))
		check = 0;
	return (check);
}

void	init_img(t_game *game)
{
	int		*width;
	int		*height;
	void	*mlx;

	width = &(game->img_width);
	height = &(game->img_height);
	*width *= 10;
	mlx = game->mlx;
	game->wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", width, height);
	game->box = mlx_xpm_file_to_image(mlx, "./img/box.xpm", width, height);
	game->floor = mlx_xpm_file_to_image(mlx, "./img/floor.xpm", width, height);
	game->hero = mlx_xpm_file_to_image(mlx, "./img/hero.xpm", width, height);
	game->door = mlx_xpm_file_to_image(mlx, "./img/door.xpm", width, height);
	if (game_img_check(game) == 0)
	{
		perror("Error\nfailed to load img");
		exit_game(game);
	}
}

void	init_p_xy(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_xy.x = x;
				game->player_xy.y = y;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	init_game(t_game *game, char *map)
{
	init_struct(game);
	init_map(map, game);
	init_p_xy(game);
	if (map_check(game) == 0)
	{
		game->error_message = "Error\ninvalid map";
		exit_game(game);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		game->error_message = "Error\nfailed to connect to server";
		exit_game(game);
	}
	init_img(game);
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * game->img_width,
			game->map_height * game->img_height, "so_long");
	if (!game->mlx_win)
	{
		game->error_message = "Error\nwindow generation failed";
		exit_game(game);
	}
}
