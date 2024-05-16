/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:09:48 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/16 16:24:30 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cub_destroy(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->texture[i])
			free(cub->texture[i]);
		if (cub->t[i])
			free(cub->t[i]);
		i++;
	}
	if (cub->map.mapping)
		free(cub->map.mapping);
	if (cub->mlx->imag)
		mlx_destroy_image(cub->mlx, cub->mlx->imag);
	if (cub->mlx->win)
		mlx_destroy_window(cub->mlx->mlx_ptr, cub->mlx->win);
	if (cub->mlx)
		free(cub->mlx);
	free(cub);
	cub = NULL;
	exit(1);
}

void	destroy_textures(int i, t_cub *c)
{
	while (i >= 0)
	{
		if (c->texture[i]->imag)
		{
			mlx_destroy_image(c->mlx, c->texture[i]->imag);
		}
		i--;
	}
}
