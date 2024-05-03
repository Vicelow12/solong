/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:14:46 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:17:43 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int keycode)
{
	static int	valid[] = {XK_a, XK_A, XK_w, XK_W, XK_s, XK_S, XK_d, XK_D, 0};
	int			i;

	i = 0;
	while (valid[i] != 0)
	{
		if (keycode == valid[i])
			return (1);
		i++;
	}
	return (0);
}

void	set_target(int keycode, int *y, int *x)
{
	if (keycode == XK_w || keycode == XK_W)
		(*y)--;
	else if (keycode == XK_s || keycode == XK_S)
		(*y)++;
	else if (keycode == XK_a || keycode == XK_A)
		(*x)--;
	else if (keycode == XK_d || keycode == XK_D)
		(*x)++;
	return ;
}

int	map_complete(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	swap_char(char *cur_pos, char *target_pos, t_game *game)
{
	if (*target_pos == 'E')
	{
		if (map_complete(game->map))
			exit_game(game);
		else
			return (0);
	}
	(game->move_count)++;
	if (ft_printf("move : %i\n", game->move_count) == -1)
		exit_game(game);
	*target_pos = *cur_pos;
	*cur_pos = '0';
	return (1);
}

int	game_input(int keycode, t_game *game)
{
	char	*cur_pos;
	char	*target_pos;
	int		x;
	int		y;

	if (keycode == XK_Escape)
		exit_game(game);
	if (check_input(keycode) == 1)
	{
		x = game->player_xy.x;
		y = game->player_xy.y;
		cur_pos = &(game->map[y][x]);
		set_target(keycode, &y, &x);
		target_pos = &(game->map[y][x]);
		if (*target_pos != '1')
		{
			if (swap_char(cur_pos, target_pos, game) == 1)
			{
				game->player_xy.x = x;
				game->player_xy.y = y;
				generate_game(game);
			}
		}
	}
	return (0);
}
