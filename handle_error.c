/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:54:52 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:29:16 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
	return ;
}

void	perror_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

int	exit_game(t_game *game)
{
	cleanup(game);
	if (game->error_message)
		perror_exit(game->error_message);
	exit(EXIT_SUCCESS);
}

void	cleanup(t_game *game)
{
	if (game->box)
		mlx_destroy_image (game->mlx, game->box);
	if (game->wall)
		mlx_destroy_image (game->mlx, game->wall);
	if (game->hero)
		mlx_destroy_image (game->mlx, game->hero);
	if (game->door)
		mlx_destroy_image (game->mlx, game->door);
	if (game->floor)
		mlx_destroy_image (game->mlx, game->floor);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->map)
		free_map(game->map);
	if (game->map_double)
		free_map(game->map_double);
	free(game->mlx);
}
