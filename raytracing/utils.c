/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:54:49 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/07 12:32:51 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_mapping(t_cub *c, char **map)
{
	int	i;
	int	len;

	i = 0;
	while (i < c->map.row)
	{
		len = ft_strlen(map[i]);
		c->map.mapping[i] = len;
		i++;
	}
}

void	change_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->board[i] != NULL)
	{
		j = 0;
		while (g->board[i][j] != '\0')
		{
			if (g->board[i][j] != '0' && g->board[i][j] != '1')
			{
				g->orientation = g->board[i][j];
				g->board[i][j] = '0';
				break ;
			}
			j++;
		}
		i++;
	}
}

int	rgb_to_int(t_game g, int flag)
{
	int	color;

	color = 0;
	if (flag == 1)
	{
		color |= (int)g.sky_rgb.r << 16;
		color |= (int)g.sky_rgb.g << 8;
		color |= (int)g.sky_rgb.b;
	}
	else
	{
		color |= (int)g.floor_rgb.r << 16;
		color |= (int)g.floor_rgb.g << 8;
		color |= (int)g.floor_rgb.b;
	}
	return (color);
}

//flaf = 1 -> floor
//flag = 0 -> sky
void	pass_to_rgb(int res, int i, t_game *g, int flag)
{
	if (flag == 0)
	{
		if (i == 0)
			g->sky_rgb.r = res;
		else if (i == 1)
			g->sky_rgb.g = res;
		else if (i == 2)
			g->sky_rgb.b = res;
	}
	else
	{
		if (i == 0)
			g->floor_rgb.r = res;
		else if (i == 1)
			g->floor_rgb.g = res;
		else if (i == 2)
			g->floor_rgb.b = res;
	}
}
