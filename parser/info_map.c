/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:50 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 14:22:04 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pass_to_rgb(int res, int i, t_game *g, int flag);

void	trim_all(t_game *game)
{
	game->tex_north = ft_strtrim(game->tex_north, "\n");
	game->tex_north = ft_strtrim(game->tex_north, " ");
	game->tex_south = ft_strtrim(game->tex_south, "\n");
	game->tex_south = ft_strtrim(game->tex_south, " ");
	game->tex_west = ft_strtrim(game->tex_west, "\n");
	game->tex_west = ft_strtrim(game->tex_west, " ");
	game->tex_east = ft_strtrim(game->tex_east, "\n");
	game->tex_east = ft_strtrim(game->tex_east, " ");
	game->floor = ft_strtrim(game->floor, "\n");
	game->floor = ft_strtrim(game->floor, " ");
	game->sky = ft_strtrim(game->sky, "\n");
	game->sky = ft_strtrim(game->sky, " ");
	if (!game->tex_north || !game->tex_south || !game->tex_west
		|| !game->tex_east || !game->floor || !game->sky)
		error_parser("No existen las coordenadas, cielo o suelo");
}

int	max_num_rgb(int *floor, int *sky)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (floor[i] < 0 || floor[i] > 255)
			return (1);
		if (sky[i] < 0 || sky[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

void	remove_space(char *str)
{
	char	*ptr;
	int		i;

	ptr = str;
	i = 0;
	while (*str)
	{
		if (*str != ' ')
			*(ptr + i++) = *str;
		str++;
	}
	*(ptr + i) = '\0';
}

int	color_rgb(char *floor, char *sky, t_game *g)
{
	int	i_floor[3];
	int	i_sky[3];
	int	i;

	remove_space(floor);
	remove_space(sky);
	if (ft_strlen(floor) > 11 || ft_strlen(floor) < 5)
		return (1);
	if (ft_strlen(sky) > 11 || ft_strlen(sky) < 5)
		return (1);
	if (check_comma(floor, sky) == 1)
		return (1);
	i = -1;
	if (check_string(floor) || check_string(sky))
		return (1);
	while (++i < 3)
	{
		i_floor[i] = ft_atoi(floor, i);
		pass_to_rgb(i_floor[i], i, g, 1);
		i_sky[i] = ft_atoi(sky, i);
		pass_to_rgb(i_sky[i], i, g, 0);
	}
	if (max_num_rgb(i_floor, i_sky) == 1)
		return (1);
	return (0);
}

void	info_map(t_game *game)
{
	trim_all(game);
	if (color_rgb(game->floor, game->sky, game) == 1)
		error_parser("Invalid floor or sky");
}
