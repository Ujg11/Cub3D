/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:01:18 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/07 12:32:40 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Hacemos los calculos de las texturas
//tex_num se inicializa a la posicion del mapa -1 para empezar en 0
//calculamos el valor de wall_x que es donde se golpeo la pared
//Mirem:
//si el raig ha golpejat en direccio horitzontal i anava cap a la dreta
//si el raig ha golpejat en direccio vertical i anava cap a dalt
//Calculem el tamany de pas per avançar entre les coordenades
//Calculem la posicio inicial de la textura
void	calc_textures(t_texture *t, t_cub *c, int line_heigth, int start)
{
	t->num = c->map.map[c->pers.map_x][c->pers.map_y] - 1;
	if (c->ray.side == 0)
		t->wall_x = c->pers.pos_y + c->ray.walldist * c->ray.ray_dir_y;
	else
		t->wall_x = c->pers.pos_x + c->ray.walldist * c->ray.ray_dir_x;
	t->wall_x -= floor(t->wall_x);
	t->x = (int)(t->wall_x * (double)T_WIDTH);
	if (c->ray.side == 0 && c->ray.ray_dir_x > 0)
		t->x = T_WIDTH - t->x - 1;
	if (c->ray.side == 1 && c->ray.ray_dir_y < 0)
		t->x = T_WIDTH - t->x - 1;
	t->step = 1.0 * T_HEIGHT / line_heigth;
	t->pos = (start - S_HEIGHT / 2 + line_heigth / 2) * t->step;
}

int	get_pixel(t_image *i, int x, int y)
{
	char	*pixel;

	pixel = i->addr + (y * i->size_l + x * (i->bpp / 8));
	return (*(int *)pixel);
}

//Farem el bucle que omplira el buffer
//Obtenim el valor 'y 'passant a int la posicio inicial i aplicant una mascara,
//de esta manera conseguimos que el rango este entre 0 y T_HEIGH -1
//Actualizamos tex_pos para avanzar a la siguiente pos de textura vertical
//Obtenemos el color del textel. tex_num representa la textura escogida y
//T_HEIGHT * tex_y + tex_x calcula la posicion del textel en la textura
void	fill_buffer(int start, int end, t_cub *c, int x)
{
	int	color;
	int	j;

	j = start;
	c->tex.num = c->ray.hit_direction;
	while (j < end)
	{
		c->tex.y = (int)c->tex.pos & (T_HEIGHT - 1);
		c->tex.pos += c->tex.step;
		c->tex.x = (int)(c->tex.wall_x * (double)T_WIDTH);
		color = get_pixel(c->texture[c->tex.num], c->tex.x, c->tex.y);
		if (color < 0)
			color = color * -1;
		if (c->ray.side == 1)
			color = (color >> 1) & 8355711;
		c->buffer[j][x] = color;
		j++;
	}
}

//Ahora tenemos la walldist. Lo siguiente es calcular la 
//altura de la linea a dibujar en la pantalla
//line_heigth: Altura en pixeles de la pantalla
void	prepare_draw_cub(t_ray *r, t_cub *c, int x)
{
	int	line_heigth;
	int	dr_start;
	int	dr_end;

	line_heigth = (int)(S_HEIGHT / r->walldist);
	dr_start = -line_heigth / 2 + S_HEIGHT / 2;
	if (dr_start < 0)
		dr_start = 0;
	dr_end = line_heigth / 2 + S_HEIGHT / 2;
	if (dr_end >= S_HEIGHT)
		dr_end = S_HEIGHT - 1;
	calc_textures(&c->tex, c, line_heigth, dr_start);
	fill_buffer(dr_start, dr_end, c, x);
}
