/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:05:46 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/07 12:32:28 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_position(char **map, t_cub *c, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x < c->map.row && y < c->map.mapping[x])
	{
		if (map[x][y] == '0')
			return (1);
	}
	return (0);
}

void	press_w_s(int key_pressed, t_cub *c, t_person *p)
{
	int	x;
	int	y;

	if (key_pressed == KEY_W)
	{
		x = (int)(p->pos_x + p->dir_x * c->ray.move_speed);
		y = (int)(p->pos_y + p->dir_y * c->ray.move_speed);
		if (check_position(c->map.map, c, x, (int)p->pos_y))
			p->pos_x += p->dir_x * c->ray.move_speed * 0.15;
		if (check_position(c->map.map, c, (int)p->pos_x, y))
			p->pos_y += p->dir_y * c->ray.move_speed * 0.15;
	}
	if (key_pressed == KEY_S)
	{
		x = (int)(p->pos_x - p->dir_x * c->ray.move_speed);
		y = (int)(p->pos_y - p->dir_y * c->ray.move_speed);
		if (check_position(c->map.map, c, x, (int)p->pos_y))
			p->pos_x -= p->dir_x * c->ray.move_speed * 0.15;
		if (check_position(c->map.map, c, (int)p->pos_x, y))
			p->pos_y -= p->dir_y * c->ray.move_speed * 0.15;
	}
}

void	press_a_d(int key_pressed, t_person *p, t_ray *r)
{
	double	d_x;
	double	p_x;

	d_x = p->dir_x;
	p_x = r->plane_x;
	if (key_pressed == KEY_A)
	{
		p->dir_x = p->dir_x * cos(r->rot_speed) - p->dir_y * sin(r->rot_speed);
		p->dir_y = d_x * sin(r->rot_speed) + p->dir_y * cos(r->rot_speed);
		r->plane_x = r->plane_x * cos(r->rot_speed)
			- r->plane_y * sin(r->rot_speed);
		r->plane_y = p_x * sin(r->rot_speed) + r->plane_y * cos(r->rot_speed);
	}
	if (key_pressed == KEY_D)
	{
		p->dir_x = p->dir_x * cos(-r->rot_speed)
			- p->dir_y * sin(-r->rot_speed);
		p->dir_y = d_x * sin(-r->rot_speed) + p->dir_y * cos(-r->rot_speed);
		r->plane_x = r->plane_x * cos(-r->rot_speed)
			- r->plane_y * sin(-r->rot_speed);
		r->plane_y = p_x * sin(-r->rot_speed) + r->plane_y * cos(-r->rot_speed);
	}
}

int	read_keys(int key_pressed, t_cub *c)
{
	if (key_pressed == LEFT_ARROW)
		key_pressed = KEY_A;
	if (key_pressed == RIGHT_ARROW)
		key_pressed = KEY_D;
	if (key_pressed == ESC)
		cub_destroy(c);
	if (key_pressed == KEY_W || key_pressed == KEY_S)
		press_w_s(key_pressed, c, &c->pers);
	if (key_pressed == KEY_A || key_pressed == KEY_D)
		press_a_d(key_pressed, &c->pers, &c->ray);
	draw_cub_loop(c);
	return (0);
}
