/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:57:36 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/16 02:01:58 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *argv1, t_game *game)
{
	int	i;

	i = ft_strlen(argv1);
	if (ft_strncmp(&argv1[i - 4], ".ber", 4) != 0)
	{
		ft_error("Error\n Map file must have .ber extension \n");
	}
	game->map.path = argv1;
}

void	get_len(t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = 0;
	fd = open(game->map.path, O_RDONLY | O_NOFOLLOW);
	if (fd < 0)
		ft_error("Error\nMap not found\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nMap is empty\n");
	game->map.x = ft_strlen(line) - 1;
	while (line)
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		if (ft_strlen(line) != game->map.x)
			ft_error("Error\nMap on x is irregular\n");
		game->map.y++;
		tmp = line;
		line = get_next_line(fd);
		free(tmp);
	}
	close(fd);
}
