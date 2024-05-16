/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:04:12 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/06 20:29:57 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_map(char **map, int i)
{
	char	aux;
	int		j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			aux = map[i][j];
			if (aux != '1' && aux != '0' && aux != ' ' && aux != 'N'
				&& aux != 'S' && aux != 'E' && aux != 'W' && aux != '\0'
				&& aux != '\n')
				error_parser("Invalid chars in map");
			j++;
		}
		i++;
	}
	return (1);
}

char	**start_board(t_game *game, int start)
{
	char	**board;
	int		i;

	i = 0;
	while (game->map[i])
		i++;
	board = (char **)malloc((i - start + 1) * sizeof(char *));
	if (!board)
		error_parser("Error: Malloc for board failed");
	i = 0;
	while (game->map[start])
	{
		board[i] = ft_strdup(game->map[start]);
		if (!board)
			error_parser("error: Malloc of the board failed");
		i++;
		start++;
	}
	board[i] = NULL;
	return (board);
}

void	clean(t_game *game, int i)
{
	int	j;

	j = -1;
	is_map(game->map, i);
	game->board = start_board(game, i);
}
