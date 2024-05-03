/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:24:09 by ngaulthi1 1       #+#    #+#             */
/*   Updated: 2024/05/03 22:18:26 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **map, t_xy begin)
{
	int	x;
	int	y;

	x = begin.x;
	y = begin.y;
	if (map[y][x] == 'F' || map[y][x] == '1' || map[y][x] == 'E')
		return ;
	else
		map[y][x] = 'F';
	floodfill(map, (t_xy){x - 1, y});
	floodfill(map, (t_xy){x + 1, y});
	floodfill(map, (t_xy){x, y - 1});
	floodfill(map, (t_xy){x, y + 1});
}

int	check_floodfill(char **map)
{
	int	x;
	int	y;
	int	check;

	y = -1;
	check = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'P')
				return (0);
			if (map[y][x] == 'E')
			{
				if (map[y - 1][x] == 'F' || map[y + 1][x] == 'F'
					|| map[y][x + 1] == 'F' || map[y][x - 1] == 'F')
					check = 1;
			}
		}
	}
	return (check);
}

int	path_check(t_game *game)
{
	floodfill(game->map_double, game->player_xy);
	return (check_floodfill(game->map_double));
}
