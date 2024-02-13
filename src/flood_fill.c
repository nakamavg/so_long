/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:13:52 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/13 20:03:19 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void handler_recursivity(t_game *game, int y, int x)
{
	if(game->map.map[y][x] == 'C' )
	{
		game->player.collectibles++;
		game->map.map[y][x] = 'F';
	}
	if(game->map.map[y][x] == 'E' )
	{
		game->player.exit = true;
		game->map.map[y][x] = 'F';
	}
	if(game->map.map[y][x] == '0' ||game->map.map[y][x] == 'P' )
	{

	game->map.map[y][x] = 'F';
 
	handler_recursivity(game, y + 1, x);
	handler_recursivity(game, y - 1, x);
	handler_recursivity(game, y, x + 1);
	handler_recursivity(game, y, x - 1);
			
	}
}
void handler_ff(t_game *game)
{	
	handler_recursivity(game , game->player.y , game->player.x);
}