/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:25:55 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/16 14:12:03 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = 0;
	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap not found\n");
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
		line = get_next_line(fd);
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
}

void	check_perimeter(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	while (x--)
	{
		if (game->map.map[0][x] != '1' || game->map.map[y - 1][x] != '1')
			ft_error("Error\nMap is not closed\n");
	}
	while (y--)
	{
		if (game->map.map[y][0] != '1' || game->map.map[y][game->map.x
			- 1] != '1')
			ft_error("Error\nMap is not closed\n");
	}
}

void	check_other_things(t_game *game, int y, int x)
{
	if (game->map.map[y][x] != '1' && game->map.map[y][x] != '0'
		&& game->map.map[y][x] != '\n')
		ft_error("Error\nChar on map Invalid\n");
}

void	count_things(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
				game->map.player++;
			else if (game->map.map[y][x] == 'C')
				game->player.c_collects++;
			else if (game->map.map[y][x] == 'E')
				game->map.count++;
			else
				check_other_things(game, y, x);
			x++;
		}
		y++;
	}
	if (game->map.player != 1 || game->map.count != 1
		|| game->player.c_collects < 1 || game->map.count != 1)
		ft_error("Error\nInvalid map\n");
}
