/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:29:56 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/06 20:39:58 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_aux_bool(t_game *game, char ***aux_bool)
{
	int	i;
	int	j;

	i = 0;
	*aux_bool = malloc((game->rows + 1) * sizeof(char *));
	if (!(*aux_bool))
		error_parser("Malloc failed");
	(*aux_bool)[game->rows] = NULL;
	while (i < game->rows + 1)
	{
		j = 0;
		(*aux_bool)[i] = malloc(ft_strlen(game->board[i]) + 1);
		if (!(*aux_bool)[i])
			error_parser("Mallocc failed");
		while (game->board[i][j])
		{
			(*aux_bool)[i][j] = '0';
			j++;
		}
		(*aux_bool)[i][j] = '\0';
		i++;
	}
}

void	fds(t_game *game, int x, int y, char **aux_bool)
{
	if (x < 0 || y < 0 || x > game->rows || y > game->columns)
	{
		game->open_map = 1;
		return ;
	}
	if (aux_bool[x][y] == '1' || game->board[x][y] == '1')
		return ;
	aux_bool[x][y] = '1';
	fds(game, x + 1, y, aux_bool);
	fds(game, x, y + 1, aux_bool);
	fds(game, x - 1, y, aux_bool);
	fds(game, x, y - 1, aux_bool);
}
