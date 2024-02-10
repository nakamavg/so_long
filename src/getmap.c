/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:57:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/10 17:44:16 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void init_structs(t_game *game)
{
	game->map.path = NULL;
	game->map.map = NULL;
	game->map.x = 0;
	game->map.y = 0;
	game->map.player = 0;
	game->map.count = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.c = 0;
	game->player.c_collects = 0;
	game->player.moves = 0;
}

void check_extension(char *argv1, t_game *game)
{
	int i;

	i = ft_strlen(argv1);
	if (argv1[i - 1] != 'r' || argv1[i - 2] != 'e' || argv1[i - 3] != 'b' || argv1[i - 4] != '.')
	{
		ft_putstr_fd("Error\n Map file must have .ber extension \n", 2);
		exit(1);
	}
	game->map.path = argv1;
}

void get_len(t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = 0;
	
	fd = open(game->map.path, O_RDONLY);
	line = get_next_line(fd);
	game->map.x = ft_strlen(line);
	while (line)
	{
		game->map.y++;
		tmp = line;
		line = get_next_line(fd);
		free(tmp);
	}
	if(game->map.y == game->map.x)
		ft_error("Error\nMap is not rectangular\n");
	
	close(fd);
}
