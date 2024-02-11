/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:25:55 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/11 19:14:01 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = 0;
	fd =open(game->map.path, O_RDONLY);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	if (!game->map.map)
		return ;
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nMap is empty\n");
	i = 0;
	while (i < game->map.y)
	{
		game->map.map[i] = line;
		line = get_next_line (fd);
		i++;
	}
	game->map.map[i] = NULL;
	close (fd);
}
