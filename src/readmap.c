/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:25:55 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/10 20:16:41 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = 0;
	fd = open(game->map.path, O_RDONLY);
	line = get_next_line(fd);
	game->map.map = malloc(sizeof(char *) * (game->map.y + 1));
	if (!game->map.map)
		ft_error("Error\nMalloc failed\n");
	

}