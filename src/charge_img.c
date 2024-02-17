/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:52:12 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/16 12:42:55 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	charge_xpm(t_game *game)
{
	int	x;
	int	y;

	game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &(x), &(y));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &(x), &(y));
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &(x), &(y));
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &(x), &(y));
	game->img.collects = mlx_xpm_file_to_image(game->mlx, COIN, &(x), &(y));
}

static void	put_images(t_game *game, int x, int y)
{
	char	current;

	current = game->map.map[y][x];
	if (current == '1')
	{
		put_wall(game, x, y);
		return ;
	}
	put_floor(game, x, y);
	if (current == 'C')
		put_collects(game, x, y);
	if (current == 'E')
		put_exit(game, x, y);
	if (current == 'P')
		put_player(game, x, y);
	if (current == 'D')
		put_player_exit(game, x, y);
}

void	get_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	charge_xpm(game);
	while (game->map.map[y] != 0)
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			put_images(game, x, y);
			x++;
		}
		y++;
	}
}
