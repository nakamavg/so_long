/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:47:31 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/16 15:09:43 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
				game->map.map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.collects);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.player);
	ft_free(game);
	exit(EXIT_SUCCESS);
}

void	put_player_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit, (x * 64),
		(y * 64));
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.player, (x
			* 64), (y * 64));
}
