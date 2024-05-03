/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:00:42 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:20:00 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	size_t	width;
	int		j;

	j = 0;
	width = ft_strlen(map[j]);
	while (map[j])
	{
		if (ft_strlen(map[j]) != width)
			return (0);
		j++;
	}
	return (1);
}

int	is_closed(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
		if (map[y++][x] != '1')
			return (0);
	y--;
	while (map[y][x])
		if (map[y][x++] != '1')
			return (0);
	x--;
	while (y >= 0)
		if (map[y--][x] != '1')
			return (0);
	y++;
	while (x >= 0)
		if (map[y][x--] != '1')
			return (0);
	return (1);
}

int	item_count(char **map)
{
	int	yx_item[5];

	yx_item[0] = -1;
	yx_item[2] = 0;
	yx_item[3] = 0;
	yx_item[4] = 0;
	while (map[++yx_item[0]])
	{
		yx_item[1] = -1;
		while (map[yx_item[0]][++yx_item[1]])
		{
			if (map[yx_item[0]][yx_item[1]] == 'P')
				(yx_item[2])++;
			else if (map[yx_item[0]][yx_item[1]] == 'E')
				(yx_item[3])++;
			else if (map[yx_item[0]][yx_item[1]] == 'C')
				(yx_item[4])++;
			else if (map[yx_item[0]][yx_item[1]] != '1'
				&& map[yx_item[0]][yx_item[1]] != '0')
				return (0);
		}
	}
	if (yx_item[2] != 1 || yx_item[3] != 1 || yx_item[4] < 1)
		return (0);
	return (1);
}

int	map_check(t_game *game)
{
	if (!(game->map) || !(game->map[0]))
		return (0);
	if (!(is_rectangle(game->map)))
		return (0);
	if (!(is_closed(game->map)))
		return (0);
	if (!(item_count(game->map)))
		return (0);
	if (!path_check(game))
		return (0);
	return (1);
}
