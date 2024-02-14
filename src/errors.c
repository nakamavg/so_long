/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:15:10 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/14 14:24:49 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void ft_free(t_game *game)
{
	int y;
		
	y = -1;
	while(game->map.map[++y])
		free(game->map.map[y]);		
	free(game->map.map);
	game->map.map = NULL;
}

void 	handler_errors(t_game *game)
{
	if(game->player.c_collects != game->player.collectibles \
	|| game->player.exit == false) 
		ft_error("Map cant played");
	ft_free(game);
}