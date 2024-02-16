# DEMASIADO LARGO
# Mis structs

- Tengo una struct principal con mas structs para solo mandar por argumentos el mismo y sea mas facil de manipular mis variables

```c
typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_image		img;
	t_player	player;
}				t_game;
```
1. El puntero necesario para iniciar la mlx
2. El puntero necesario para la ventana
3. una estructura mapa con las variables necesarias 
	- `char ** map ` es donde guardo el mapa allocado en memoria
	- tamaño en el mapa de las x
	- tamañp en el mapa de las y
	- ruta del mapa
	- numero de players(para comprobar si hay errores en el mapa)
	- numero de salidas(para comprobar si hay errores en el mapa)
4. una estructura img con los punteros para inicializar las imagenes del juego
5. una estructura player para saber donde esta el jugador 
	- donde guardo el numero de tokens que son los que le quedan al jugador y los totales 
	- el numero de movimientos 
	- y un booleano para saber si la ssalida existe
## Parte del mapa
- Este es el primer proyecto en el que el que tuve que usar la maravillosa
libreria grafica de 42.

- Habra gente que decida empezar por lo grafico , en mi caso particular he 
decidido empezar por lo que se, que era controlar los imputs es decir el mapa
que nos permite jugar.

- El mapa sigue una estructura en la cual el perimetro debe estar cerrado por 
unos tal que asi
```plaintext
111111111111111111111111
1E0000000000000000000C11
1000000000C000C000001111
1000000000C000C000CCC001
1000000000CCCCC00000C001
1P0000000000000000CCC001
111111111111111111C11111
111111111111111111CCCCC1
111111111111111111111111
```
- Tambien debemos comprobar que el tamaño de las x sea igual para todos 
esto lo hago en [get_len](/src/getmap.c).

- Lo consigo haciendo un strlen de get_next_line al fd - 1 
por que necesitamos que sea menos uno por que la ultima linea a comparar no va
a ser un salto de linea y siempre va a tener un caracter menos.

- la y la obtengo haciendo un simple y++ por cada linea llena que me retorne 
el propio gnl.

- hacemos un free de cada linea para no tener leaks.

- Al final de estas comprobaciones hago en [read_map](/src/read_map.c) 
 el malloc para el tamaño de y e x.

## el Flood Fill

- Consta de 2 ccosas funciones un ccontrolador inicial
donde le mando la posicion inicial del jugador en y e x

- y el flood fill en si mismo que se va a mandar de forma recursiva
a todas las casillas pegadas a cada posicion y e x del mapa poniendo como tope los muros y las f (que son las casillas por donde mi funcion a pasado previamente para que no vuelva a pasar por ahi)
- tambien controlamos el numero de C y si puede llegar a la E

al final si las C a las que puedo llegar son las mismas que hago en la funcion previa de count things y puedo llegar a la salida el mapa es valido

## Despues del FF

Lo primero de todo si comprobamos que el mapa esta bien libero el mapa porque esta lleno de F del FF

y vuelvo hacer una llamada a readmap para tener el mapa limpito.

## Funciones de la mlx
- Necesito un puntero void para inicializar la mlx con
	`mlx_init()`
- Tambien otro puntero para la ventana
	`mlx_new_window(game.mlx, game.map.x * 64, game.map.y * 64,"so_long"); `
	 - esta funcion recibe el puntero anterior y un tamaño en mi caso multiplico la x y la y por 64 que son el tamaño que va ocupar mis imagenes.
## Imagenes

- Dentro de mi struct game tengo la anteriormente mencionada imagenes que son punteros neccesarios para cargar mis imagenes y luego usarlas
`game->img.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &(x), &(y));`
- Player es un define a una ruta donde esta el xpm

- Como las coloco en el mapa?
	- itero mi mapa y compruebo que char ES 
	`mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.collects, (x* 64), (y * 64));`

## los hooks de la mlx
```c
void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, destroy_window, game);
	mlx_hook(game->mlx_win, 2, 1, handler_keys, game);
}
```
- Mi primier hook es para la x de la ventana cierre el juego y le digo cuando le doy a la x haga la funcion 
destroy window

```c
int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.collects);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.player);
	ft_free(game);
	exit(EXIT_SUCCESS);
}
```

- mi funcion para manejar las teclas fue mi odisea final

- Tenia el  problema de que queria hacer una funcion para cada movimiento al final desarrolle  una para todos en las cuales les envio lo unico que variaba el modificador de x e y

- aun asi se me iba de muchas lineas
y saque dos casos afuera el checkeo de 0 y de unos.
