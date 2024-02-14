/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:57:02 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/14 14:26:23 by dgomez-m         ###   ########.fr       */
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
int	key_hook(int keycode, t_game *game)
{
	printf("letra pulsada%d\n" ,keycode);
	return (0);
}

void	print_map(t_game *game)
{
	int	x;

	printf("%s", game->map.map[0]);
	printf("%s", game->map.map[1]);
	printf("%s", game->map.map[2]);
	printf("%s", game->map.map[3]);
}
void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, destroy_window, game);
	mlx_hook(game->mlx_win, 2, 1, handler_keys, game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	check_number_of_args(argc);
	ft_bzero(&game, sizeof(t_game));
	check_extension(argv[1], &game);
	get_len(&game);
	read_map(&game);
	check_perimeter(&game);
	count_things(&game);
	get_player(&game);
	handler_ff(&game);
	handler_errors(&game);
	if (game.map.map)
		print_map(&game);
	read_map(&game);
		print_map(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.x * 64, \
	game.map.y * 64, "so_long");
	hooks(&game);
	get_images(&game);
	

	mlx_loop(game.mlx);
	return (0);
}
