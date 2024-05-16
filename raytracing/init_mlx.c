/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:42:54 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/16 15:50:03 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	draw_cub_loop(void *param)
{
	do_cub((t_cub *)param);
	return (0);
}

void	put_first_img(t_cub *c)
{
	void	*img;
	int		w;
	int		h;

	w = S_WIDTH;
	h = S_HEIGHT;
	img = mlx_xpm_file_to_image(c->mlx->mlx_ptr,
			"raytracing/Foto_panas.xpm", &w, &h);
	if (img != NULL)
	{
		mlx_put_image_to_window(c->mlx->mlx_ptr, c->mlx->win, img, 0, 0);
		mlx_destroy_image(c->mlx->mlx_ptr, img);
	}
}

void	init_mlx(t_mlx *m, t_cub *cub)
{
	put_first_img(cub);
	mlx_hook(m->win, 17, 0, cub_destroy, cub);
	mlx_hook(m->win, 2, (1L << 0), read_keys, cub);
	mlx_loop(m->mlx_ptr);
}
