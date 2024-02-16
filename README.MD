#DEMASIADO LARGO

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

 