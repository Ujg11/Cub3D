/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:37:35 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 16:08:32 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_parser(t_game *game)
{
	game->columns = 0;
	game->rows = 0;
	game->coordinates = 0;
	game->tex_north = NULL;
	game->tex_south = NULL;
	game->tex_west = NULL;
	game->tex_east = NULL;
	game->floor = NULL;
	game->sky = NULL;
	game->player = 0;
}

void	start_parser(char *file, t_game *game)
{
	int	i;
	int	x;

	i = 0;
	init_parser(game);
	check_map(file, game);
	i = check_coordinates(game);
	clean(game, i);
	valid_map(game);
	x = -1;
	while (game->map[++x])
		free(game->map[x]);
	free(game->map);
}
