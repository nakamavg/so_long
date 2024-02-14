/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:52:12 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/14 07:32:21 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void charge_img(t_game *game)
{
	int x;
	int y;
	game->img.wall = mlx_xpm_file_to_image(game->mlx,WALL,&(x), &(y));
	game->img.floor = mlx_xpm_file_to_image(game->mlx,FLOOR,&(x), &(y));
	game->img.exit = mlx_xpm_file_to_image(game->mlx,EXIT,&(x), &(y));
	game->img.player = mlx_xpm_file_to_image(game->mlx,PLAYER,&(x), &(y));
	game->img.collects = mlx_xpm_file_to_image(game->mlx,COIN,&(x), &(y));
	
}
void load_img(t_game *game, int y, int x)
{
	if(game->map.map[y][x] == '1')
		mlx_put_image_to_window (game->mlx, game->mlx_win, \
		game->img.wall, (x * 64), (y * 64));
	
	if(game->map.map[y][x] == '0')
		mlx_put_image_to_window (game->mlx, game->mlx_win, \
		game->img.floor, (x * 64), (y * 64));
	if(game->map.map[y][x] == 'E')
		mlx_put_image_to_window (game->mlx, game->mlx_win, \
		game->img.exit, (x * 64), (y * 64));
	if(game->map.map[y][x] == 'P')
		mlx_put_image_to_window (game->mlx, game->mlx_win, \
		game->img.player, (x * 64), (y * 64));		
}

void put_img(t_game *game)
{
	int y;
	int x;
	
	y = 0;
	
	charge_img(game);
	while(game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			load_img(game, x, y);
			x++;
		}
		y++;
	}
}