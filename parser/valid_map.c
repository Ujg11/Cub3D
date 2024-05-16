/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:44:01 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 16:55:50 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_player(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				game->player = map[i][j];
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
	if (game->player == 0)
		error_parser("error: player not found");
}

void	valid_map(t_game *game)
{
	char	**aux_bool;
	int		i;

	game->open_map = 0;
	i = 0;
	game->rows = count_rows(game->board) - 1;
	game->columns = count_columns(game->board) - 1;
	strtrim_map(game);
	find_player(game, game->board);
	init_aux_bool(game, &aux_bool);
	game->open_map = padding_map_two(game, game->rows + 1, game->columns);
	if (only_one_player(game->board, "NSEW"))
		error_parser("Too many players");
	replace_space(game);
	i = game->rows;
	while (i >= 0)
	{
		free(aux_bool[i]);
		i--;
	}
	free(aux_bool);
	if (game->open_map == 1)
		error_parser("Map_open");
}
