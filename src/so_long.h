/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:58:44 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/10 17:44:31 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	char	*path;
	int		player;
	int		count;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		c;
	int		c_collects;
	int		moves;
}	t_player;

typedef struct s_image
{
	void	*collects;
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	int		w;
	int		h;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_image		img;
	t_player	player;
}	t_game;

void 	check_extension(char *argv1, t_game *game);
void	init_structs( t_game *game);
void	get_map(int fd, t_game *game);
void	get_len(t_game *game);
void	ft_error(char *message);

#endif