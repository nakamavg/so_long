/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-m <dgomez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:58:44 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/02/16 02:01:04 by dgomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WALL "textures/wall.xpm"
# define FLOOR "textures/flor.xpm"
# define PLAYER "textures/player.xpm"
# define EXIT "textures/exit.xpm"
# define COIN "textures/coins.xpm"
# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 0x35
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	char		*path;
	int			player;
	int			count;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			tokens;
	int			c_collects;
	int			moves;
	bool		exit;
}				t_player;

typedef struct s_image
{
	void		*collects;
	void		*player;
	void		*wall;
	void		*floor;
	void		*exit;
	int			w;
	int			h;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_image		img;
	t_player	player;
}				t_game;

void			check_extension(char *argv1, t_game *game);
void			get_len(t_game *game);
void			ft_error(char *message);
void			read_map(t_game *game);
void			print_map(t_game *game);
void			check_perimeter(t_game *game);
void			count_things(t_game *game);
void			get_player(t_game *game);
void			handler_ff(t_game *game);
void			handler_errors(t_game *game);
void			get_images(t_game *game);
int				destroy_window(t_game *game);
int				handler_keys(int keycode, t_game *game);
void			ft_free(t_game *game);
void			put_player_exit(t_game *game, int x, int y);
void			put_player(t_game *game, int x, int y);
void			put_exit(t_game *game, int x, int y);
void			put_collects(t_game *game, int x, int y);
void			put_wall(t_game *game, int x, int y);
void			put_floor(t_game *game, int x, int y);

#endif