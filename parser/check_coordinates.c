/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:59:54 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 14:04:38 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	no_so(t_game *game, char *gam)
{
	int	i;

	i = 0;
	while (gam[i] == ' ' && gam[i])
		i++;
	if (gam[i] == 'N' && gam[i + 1] == 'O' && gam[i + 2] == ' ')
	{
		if (game->tex_north == NULL)
			game->tex_north = ft_substr(gam, i + 3, ft_strlen(gam));
		else
			error_parser("Info ducplicate");
		game->coordinates += 1;
	}
	else if (gam[i] == 'S' && gam[i + 1] == 'O' && gam[i + 2] == ' ')
	{
		if (game->tex_south == NULL)
			game->tex_south = ft_substr(gam, i + 3, ft_strlen(gam));
		else
			error_parser("Iinfo duplicate");
		game->coordinates += 1;
	}
}

void	we_ea(t_game *game, char *gam)
{
	int	i;

	i = 0;
	while (gam[i] == ' ' && gam[i])
		i++;
	if (gam[i] == 'W' && gam[i + 1] == 'E' && gam[i + 2] == ' ')
	{
		if (game->tex_west == NULL)
			game->tex_west = ft_substr(gam, i + 3, ft_strlen(gam));
		else
			error_parser("Duplicate info");
		game->coordinates += 1;
	}
	else if (gam[i] == 'E' && gam[i + 1] == 'A' && gam[i + 2] == ' ')
	{
		if (game->tex_east == NULL)
			game->tex_east = ft_substr(gam, i + 3, ft_strlen(gam));
		else
			error_parser("DDuplicate info");
		game->coordinates += 1;
	}
}

void	f_c(t_game *game, char *gam)
{
	int	i;

	i = 0;
	while (gam[i] == ' ' && gam[i])
		i++;
	if (gam[i] == 'F' && gam[i + 1] == ' ')
	{
		if (game->floor == NULL)
			game->floor = ft_substr(gam, i + 2, ft_strlen(gam));
		else
			error_parser("AAAAAAAA");
		game->coordinates += 1;
	}
	else if (gam[i] == 'C' && gam[i + 1] == ' ')
	{
		if (game->sky == NULL)
			game->sky = ft_substr(gam, i + 2, ft_strlen(gam));
		else
			error_parser("OOOOOOOO");
		game->coordinates += 1;
	}
}

int	trash_inside_map(char *s)
{
	if (s[0] == '\n' && s[1] == '\0')
		return (0);
	return (1);
}

char	check_coordinates(t_game *game)
{
	int	aux;
	int	i;

	i = 0;
	while (game->map[i])
	{
		aux = game->coordinates;
		no_so(game, game->map[i]);
		we_ea(game, game->map[i]);
		f_c(game, game->map[i]);
		if (trash_inside_map(game->map[i]) == 1 && aux == game->coordinates)
			error_parser("Is not enough info");
		i++;
		if (game->coordinates == 6)
			break ;
	}
	if (game->coordinates != 6)
		error_parser("Exceeded the number of coordinate");
	info_map(game);
	return (i);
}
