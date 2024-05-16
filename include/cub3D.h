/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:06:46 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 16:58:21 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

/*****************************************************
 *					  STRUC PARSER					 *
 *****************************************************/

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct game
{
	char	**map;
	int		coordinates;
	int		rows;
	int		columns;
	char	*tex_north;
	char	*tex_south;
	char	*tex_west;
	char	*tex_east;
	char	*floor;
	char	*sky;
	char	player;
	int		player_x;
	int		player_y;
	char	**board;
	char	orientation;//nueva
	int		open_map;
	t_color	sky_rgb;
	t_color	floor_rgb;
}	t_game;

/*****************************************************
 *					CHECK_COORDINATES				 *
 *****************************************************/

void	no_so(t_game *game, char *gam);
void	we_ea(t_game *game, char *gam);
void	f_c(t_game *game, char *gam);
int		trash_inside_map(char *s);
char	check_coordinates(t_game *game);

/*****************************************************
 *					  CHECK_MAP						 *
 *****************************************************/

int		count_rowss(char *file);
int		check_map(char *file, t_game *game);

/*****************************************************
 *					  	CLEAN						 *
 *****************************************************/

int		is_map(char **map, int i);
char	**start_board(t_game *game, int start);
void	clean(t_game *game, int i);

/*****************************************************
 *					 EXTENSION						 *
 *****************************************************/

void	check_xtension(char *s);
void	strtrim_map(t_game *game);
void	replace_space(t_game *game);

/*****************************************************
 *					  	FDS							 *
 *****************************************************/

void	init_aux_bool(t_game *game, char ***aux_bool);
void	fds(t_game *game, int x, int y, char **aux_bool);

/*****************************************************
 *					  INFO_MAP						 *
 *****************************************************/

void	trim_all(t_game *game);
int		max_num_rgb(int *floor, int *sky);
int		color_rgb(char *floor, char *sky, t_game *g);
void	info_map(t_game *game);

/*****************************************************
 *					  MAP_CLOSE						 *
 *****************************************************/

int		count_columns(char **map);
int		count_rows(char **map);

/*****************************************************
*					  UTILS							 *
 *****************************************************/

int		check_comma(char *floor, char *sky);
void	error_parser(char *msg);

/*****************************************************
*					  UTILS	2						 *
 *****************************************************/

int		padding_map_two(t_game *game, int rows, int cols);

/*****************************************************
*					  UTILS	3						 *
 *****************************************************/

char	**allocate_expanded_map(int rows, int cols);
int		only_one_player(char **map, char *or);
int		check_string(char *s);

/*****************************************************
 *					  VALID_MAP						 *
 *****************************************************/

void	find_player(t_game *game, char **map);
void	valid_map(t_game *game);

/*****************************************************
 *					  PARSER						 *
 *****************************************************/

void	init_parser(t_game *game);
void	start_parser(char *file, t_game *game);

/*****************************************************
 *					  MAIN							 *
 *****************************************************/

int		main(int argc, char **argv);

/*****************************************************
 *					  RAYTRACER						 *
 *****************************************************/

# define S_WIDTH 1800
# define S_HEIGHT 1300
# define T_WIDTH 64 //amplada de la textura en textels
# define T_HEIGHT 64 //alçada de la textura en textels

# define PI 3.14159265

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

# define N 0
# define S 1
# define W 2
# define E 3

# define MOVE_SPEED 1
# define ROT_SPEED 0.08

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*imag;
	char		*addr;
	int			size_l;
	int			bpp;
	int			endian;
}	t_mlx;

typedef struct s_image
{
	void		*imag;
	char		*addr;
	int			size_l;
	int			bpp;
	int			endian;
}	t_image;

typedef struct s_ray
{
	double		camera_x; //coordenada X en l'espai de la camera
	double		ray_dir_x; //pos X del vector rayo
	double		ray_dir_y; //pos Y del vectpr rayo
	double		sidedist_x; //longitud X del raig desde el
							//punt inicial fins al seguent costat x
	double		sidedist_y; //longitud Y del raig desde el punt inicial
							//fins al seguent costat y
	double		delta_dist_x; //longitud del raig desde un costat X
							//fins al seguent costat X
	double		delta_dist_y; //longitud del raig desde un costat Y
							//fins al seguent costat Y
	double		walldist; //longitud del raig (de la càmara a la paret)
					//en quina direcció avançar en la X o en la Y (+1 o -1)
	int			step_x; //si el raig té una X negativa sera -1, sino 1
	int			step_y; //si el raig té una Y negativa sera -1, sino 1
	int			hit; //mira si hi ha hagut un cop a la paret
	int			hit_direction; //direccio de la textura
	int			side; //ha sigut un NS o un EW mur el del cop
	double		move_speed; //esta en quadrats / segon
	double		rot_speed; //esta en radians / segon
	double		plane_x; //la versió 2D ray caster del pla de la camara
	double		plane_y; //la versió 2D ray caster del pla de la camara
}	t_ray;

typedef struct s_texture
{
	int			num; //quina textura en funcio del tipus de mosaic golpejat
	double		wall_x; //la posicio exacta on s'ha golpejat la paret
	int			x; //la coordenada x dins de la textura que s'utilitzara
	int			y; //la coordenada y dins de la textura que s'utilitzara
	double		step; //paso para avanzar en las coordenadas de textura
	double		pos;//coordenada vertical en la textura per obtenir el color
					//del textel que s'assignara al pixel en la pantalla
}	t_texture;

typedef struct s_map
{
	char	**map;
	//t_color	floor; //color del terra
	//t_color	ceiling; //color del cel
	int		floor;
	int		ceiling;
	int		col; //numero de columnes
	int		row; //numero de files
	int		*mapping;
}	t_map;

typedef struct s_person
{
	double		pos_x; //posicion en x
	double		pos_y; //posicion en y
	double		dir_x; //vector de direccio pos x
	double		dir_y; //vector de direccio pos y
	int			map_x; //cuadrat on ens trobem en x
	int			map_y; //cuadrat on ens trobem en y
	double		fov;//camp de visio (en radians)
}	t_person;

typedef struct s_cub
{
	t_mlx		*mlx;
	t_ray		ray;
	t_map		map;
	t_person	pers;
	t_texture	tex;

	t_image		*texture[4];
	char		*t[4];//nombres de las tex (N,S,W,E)
	uint32_t	buffer[S_HEIGHT][S_WIDTH]; //coordenada 'y' primer
}	t_cub;

//init_cub.c
void	init_cub(t_cub *c, t_game g);

//init_mlx.c
void	init_mlx(t_mlx *m, t_cub *c);
int		draw_cub_loop(void *param);

//utils.c
void	fill_mapping(t_cub *c, char **map);
void	change_map(t_game *g);
int		rgb_to_int(t_game g, int flag);
void	pass_to_rgb(int res, int i, t_game *g, int flag);

//orientation.c
void	orientation(t_person *p, t_ray *r, t_game g);

//do_cub.c
void	draw_buffer(int width, int height, t_cub *c);
void	clean_buffer(t_cub *c, int w, int h);
void	do_cub(t_cub *cub);

//raycasting.c
void	ray_dir_and_pos(t_ray *r, t_person *p, int x);
void	ray_calc_sidedists(t_ray *r, t_person *p);
void	ray_dda(t_ray *r, t_person *p, char **map);

//textures.c
void	prepare_draw_cub(t_ray *r, t_cub *c, int x);

//destroy.c
int		cub_destroy(t_cub *cub);
void	destroy_textures(int i, t_cub *c);

//read_keys.c
int		read_keys(int key_pressed, t_cub *c);

//init_graphics.c
void	raytracing(t_game g);

#endif
