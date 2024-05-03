/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:14:58 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/05/03 22:36:30 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		perror_exit("Error\nunvalid number of arguments");
	init_game(&game, argv[1]);
	generate_game(&game);
	mlx_hook(game.mlx_win, KeyPress, KeyPressMask, game_input, &game);
	mlx_hook(game.mlx_win, DestroyNotify, 1L << 17, exit_game, &game);
	mlx_loop(game.mlx);
}
