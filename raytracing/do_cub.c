/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:18:20 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/07 12:30:26 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_color_to_pixel(t_mlx *c, int x, int y, int color)
{
	char	*dst;

	dst = c->addr + (y * c->size_l + x * (c->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_back(int width, int height, t_cub *c)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y < height / 2)
				color = c->map.ceiling;
			else
				color = c->map.floor;
			put_color_to_pixel(c->mlx, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(c->mlx->mlx_ptr, c->mlx->win, c->mlx->imag, 0, 0);
}

void	draw_buffer(int width, int height, t_cub *c)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	draw_back(width, height, c);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			color = c->buffer[y][x];
			if (color != 0)
				put_color_to_pixel(c->mlx, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(c->mlx->mlx_ptr, c->mlx->win, c->mlx->imag, 0, 0);
}

void	clean_buffer(t_cub *c, int w, int h)
{
	int	x;
	int	y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			c->buffer[y][x] = 0;
			x++;
		}
		y++;
	}
}

//Hacemos el bucle principal que hara el raytraing, calculara
//las texturas y rellenara el buffer
//Despues del bucle, printamos el dibujo y limpiamos el buffer
//Actualizamos el tiempo de entrada y el contador de tiempo de frame
//Calculamos la velocidad de movimiento (cuadrados /segundo)
//Calculamos la velocidad angular (radianes /segundo)
void	do_cub(t_cub *cub)
{
	int	x;
	int	w;
	int	h;

	w = S_WIDTH;
	h = S_HEIGHT;
	x = 0;
	mlx_clear_window(cub->mlx->mlx_ptr, cub->mlx->win);
	while (x < S_WIDTH)
	{
		ray_dir_and_pos(&cub->ray, &cub->pers, x);
		ray_calc_sidedists(&cub->ray, &cub->pers);
		ray_dda(&cub->ray, &cub->pers, cub->map.map);
		prepare_draw_cub(&cub->ray, cub, x);
		x++;
	}
	draw_buffer(S_WIDTH, S_HEIGHT, cub);
	clean_buffer(cub, S_WIDTH, S_HEIGHT);
	cub->ray.move_speed = MOVE_SPEED;
	cub->ray.rot_speed = ROT_SPEED;
}
