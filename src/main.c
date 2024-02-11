/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:57:02 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/11 19:15:09 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1);
}

static void	check_number_of_args(int argc)
{
	if (argc != 2)
	{
		ft_error("Error\nInvalid number of arguments\n");
	}
}

void	print_map(t_game *game)
{
	int	x;


		ft_printf("%s", game->map.map[0]);
		ft_printf("%s", game->map.map[1]);
		ft_printf("%s", game->map.map[2]);
		ft_printf("%s", game->map.map[3]);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error\nMalloc failed\n");
	check_number_of_args(argc);
	init_structs(game);
	check_extension(argv[1], game);
	printf("game->map.path: %s\n", game->map.path);
	printf("game->map.path: %s\n", game->map.path);
	get_len(game);
	read_map(game);
	print_map(game);
	return (0);
}
