/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:58:29 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/07 12:32:10 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	orientation_aux(t_person *p, t_ray *r)
{
	p->dir_x = 0;
	p->dir_y = 1;
	r->plane_x = 0.66;
	r->plane_y = 0;
}

void	orientation(t_person *p, t_ray *r, t_game g)
{
	if (g.orientation == 'N')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		r->plane_x = 0;
		r->plane_y = 0.66;
	}
	else if (g.orientation == 'S')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		r->plane_x = 0;
		r->plane_y = -0.66;
	}
	else if (g.orientation == 'E')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		r->plane_x = -0.66;
		r->plane_y = 0;
	}
	else if (g.orientation == 'W')
		orientation_aux(p, r);
}
