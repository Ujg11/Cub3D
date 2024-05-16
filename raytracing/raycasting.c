/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:14:39 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/06 16:50:51 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Calculamos la posicion y la direccion del rayo
//Calculamos en que casilla del mapa estamos
//Calculamos la longitud del rayo desde costado x o y hasta el siguiente
//El 1e30 es para proteger la división entre 0 que sea "infinito"
void	ray_dir_and_pos(t_ray *r, t_person *p, int x)
{
	r->camera_x = 2 * x / (double)S_WIDTH - 1;
	r->ray_dir_x = p->dir_x + r->plane_x * r->camera_x;
	r->ray_dir_y = p->dir_y + r->plane_y * r->camera_x;
	p->map_x = (int)p->pos_x;
	p->map_y = (int)p->pos_y;
	r->sidedist_x = 0;
	r->sidedist_y = 0;
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
	r->walldist = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->hit = 0;
	r->side = 0;
}

//Calculem les sidedists (distancia del punt on ens
// trobem fins al costat del quadrat)
//Indiquem la direccio posant les variables step a 1 o -1
//d = (d desde pos actual del ray hasta el borde izquierdo celda actual)
// * delta_dist_x
//d = (d desde pos actual del rayo hasta el borde derecho celda actual)
// * delta_dist_x
void	ray_calc_sidedists(t_ray *r, t_person *p)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (p->pos_x - p->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (p->map_x + 1 - p->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (p->pos_y - p->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (p->map_y + 1 - p->pos_y) * r->delta_dist_y;
	}
}

//Miramos la orientacion del cubo al que hemos chocado
void	search_orientation(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->step_x > 0)
			r->hit_direction = S;
		else
			r->hit_direction = N;
	}
	else
	{
		if (r->step_y > 0)
			r->hit_direction = E;
		else
			r->hit_direction = W;
	}
}

//Hacemos el DDA con los calculos previos hasta que chocamos contra una pared
//Miramos que direccion es mas cercana y nos movemos para ella
//El side indica si la pared es este-oeste (0) o es norte-sur(1)
//Vemos si emos llegado a la pared (map[x][y] > 0)
//Por ultimo calculamos la distancia perpendicular hasta la pare mas cercana
//restando la longitud total - la longitud desde la posicion donde estamos real
void	ray_dda(t_ray *r, t_person *p, char **map)
{
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->delta_dist_x;
			p->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->delta_dist_y;
			p->map_y += r->step_y;
			r->side = 1;
		}
		if (map[p->map_x][p->map_y] == '1')
		{
			r->hit = 1;
			search_orientation(r);
		}
	}
	if (r->side == 0)
		r->walldist = r->sidedist_x - r->delta_dist_x;
	else
		r->walldist = r->sidedist_y - r->delta_dist_y;
}
