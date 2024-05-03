/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:54:40 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:21:34 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, int x, int y)
{
	void	*mlx;
	void	*mlx_win;
	int		img_x;
	int		img_y;

	img_x = game->img_width * x;
	img_y = game->img_height * y;
	mlx = game->mlx;
	mlx_win = game->mlx_win;
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(mlx, mlx_win, game->wall, img_x, img_y);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(mlx, mlx_win, game->floor, img_x, img_y);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(mlx, mlx_win, game->box, img_x, img_y);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(mlx, mlx_win, game->door, img_x, img_y);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(mlx, mlx_win, game->hero, img_x, img_y);
}

void	generate_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
	return ;
}
