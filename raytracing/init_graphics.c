/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:56:03 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/07 12:30:55 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raytracing(t_game g)
{
	t_cub	*c;

	c = malloc(sizeof(t_cub));
	if (!c)
		exit(1);
	c->mlx = malloc(sizeof(t_mlx));
	if (!c->mlx)
		cub_destroy(c);
	init_cub(c, g);
	init_mlx(c->mlx, c);
}
