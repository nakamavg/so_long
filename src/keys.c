/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:33 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/14 14:09:55 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{	
	if (game->map.map[game->player.y - 1][game->player.x] == '1')
			return ;
	else if (game->map.map[game->player.y - 1][game->player.x] == 'C')
		{	
			game->player.collectibles--;
			game->map.map[game->player.y][game->player.x] = '0';
			game->map.map[game->player.y - 1][game->player.x] = 'P';
			game->player.y--;
			get_images (game);
			ft_printf ("moves -> %d\n", game->player.moves++);
		}
		else if (game->map.map[game->player.y - 1][game->player.x] == 'E' \
			&& game->player.collectibles == 0)
			destroy_window(game);
		else if (game->map.map[game->player.y - 1][game->player.x] == 'E'\
			&& game->player.collectibles > 0)
		{
			game->map.map[game->player.y][game->player.x] = '0';
			game->map.map[game->player.y - 1][game->player.x] = 'D';
			game->player.y--;
			get_images (game);
			ft_printf ("moves -> %d\n", game->player.moves++);
		}
	}
void	move_down(t_game *game)
{
	if (game->map.map[game->player.y + 1][game->player.x] != '1')
	{
		if (game->map.map[game->player.y + 1][game->player.x] == 'C')
			game->player.collectibles--;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y - 1][game->player.x] = 'P';
		game->player.y--;
		get_images (game);
		ft_printf ("moves -> %d\n", game->player.moves++);
	}
	if (game->map.map[game->player.y - 1][game->player.x] == 'E' \
	&& game->player.collectibles == 0)
		destroy_window(game);

}
int handler_keys(int keycode, t_game *game)
{
	if(keycode == Q || keycode == ESC )
		destroy_window(game);
	else if(keycode == W || keycode == KEY_UP)
			move_up(game);
	else if(keycode == S || keycode == KEY_DOWN)
			move_down(game);
			
			
}