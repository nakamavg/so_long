/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:57:02 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/10 19:21:19 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 void ft_error(char *message)
{
	ft_printf("%s",message);
	exit(1);
}
static void check_number_of_args(int argc)
{
	if (argc != 2)
	{
		ft_error("Error\nInvalid number of arguments\n");
	}
}

int	main(int argc, char **argv)
{
	t_game 	*game;
	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error\nMalloc failed\n");
	
	check_number_of_args(argc);
	check_extension(argv[1], game);
	init_structs(game);
	get_len(game);
	return (0);
}
