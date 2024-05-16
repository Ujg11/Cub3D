/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:31:24 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/16 16:25:23 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_cub *c)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	w = T_WIDTH;
	h = T_HEIGHT;
	while (i < 4)
	{
		c->texture[i] = malloc(sizeof(t_image));
		if (!c->texture[i])
			cub_destroy(c);
		c->texture[i]->imag = mlx_xpm_file_to_image(c->mlx->mlx_ptr,
				c->t[i], &w, &h);
		if (!c->texture[i]->imag)
		{
			printf("Error al cargar las texturas\n");
			exit(1);
		}
		c->texture[i]->addr = mlx_get_data_addr(c->texture[i]->imag,
				&c->texture[i]->bpp, &c->texture[i]->size_l,
				&c->texture[i]->endian);
		i++;
	}
}

t_person	init_person(t_game g)
{
	t_person	p;
	double		fov_rad;

	p.pos_x = g.player_x + 0.5;
	p.pos_y = g.player_y + 0.5;
	p.map_x = (int)p.pos_x;
	p.map_y = (int)p.pos_y;
	fov_rad = 2 * atan2(0.66, 1.0);
	p.fov = fov_rad * (180 / PI);
	return (p);
}

t_ray	init_ray(void)
{
	t_ray	r;

	r.camera_x = -1;
	r.ray_dir_x = 0;
	r.ray_dir_y = 0;
	r.sidedist_x = 0;
	r.sidedist_y = 0;
	r.delta_dist_x = 0;
	r.delta_dist_y = 0;
	r.walldist = 0;
	r.step_x = 0;
	r.step_y = 0;
	r.hit = 0;
	r.move_speed = 0;
	r.rot_speed = 0;
	return (r);
}

void	init_cub_structure(t_cub *c, t_game g)
{
	c->map.map = g.board;
	c->map.col = g.columns;
	c->map.row = g.rows;
	c->t[0] = ft_strdup(g.tex_north);
	c->t[1] = ft_strdup(g.tex_south);
	c->t[2] = ft_strdup(g.tex_west);
	c->t[3] = ft_strdup(g.tex_east);
	c->map.ceiling = rgb_to_int(g, 1);
	c->map.floor = rgb_to_int(g, 0);
	c->map.mapping = malloc(g.rows * sizeof(int));
	if (!c->map.mapping)
		cub_destroy(c);
	fill_mapping(c, c->map.map);
}

void	init_cub(t_cub *c, t_game g)
{
	init_cub_structure(c, g);
	c->pers = init_person(g);
	c->ray = init_ray();
	orientation(&(c->pers), &(c->ray), g);
	c->mlx->mlx_ptr = mlx_init();
	if (!c->mlx->mlx_ptr)
		cub_destroy(c);
	c->mlx->win = mlx_new_window(c->mlx->mlx_ptr,
			S_WIDTH, S_HEIGHT, "Cub3D");
	if (!c->mlx->win)
		cub_destroy(c);
	c->mlx->imag = mlx_new_image(c->mlx->mlx_ptr, S_WIDTH, S_HEIGHT);
	if (!c->mlx->imag)
		cub_destroy(c);
	c->mlx->addr = mlx_get_data_addr(c->mlx->imag, &c->mlx->bpp,
			&c->mlx->size_l, &c->mlx->endian);
	init_textures(c);
}
