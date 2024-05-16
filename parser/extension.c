/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:18:45 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 13:07:49 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_xtension(char *s)
{
	int	i;

	i = 0;
	i = ft_strlen(s) - 1;
	if (i < 4)
		error_parser("No hay extension bebe");
	if (s[i - 1] != 'b' && s[i - 2] != 'u' && s[i - 3] != 'c' \
			&& s[i - 4] == '.')
		error_parser("Map file must have the '.cub' extension 🤕");
}

void	strtrim_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->board[i])
	{
		game->board[i] = ft_strtrim(game->board[i], "\n");
		if (!game->board[i])
			error_parser("Board failed");
		i++;
	}
}

void	replace_space(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->board[i])
	{
		j = 0;
		while (game->board[i][j] && game->board[i][j] == ' ')
			j++;
		while (game->board[i][j])
		{
			if (game->board[i][j] == ' ')
				game->board[i][j] = '0';
			j++;
		}
		i++;
	}
}
