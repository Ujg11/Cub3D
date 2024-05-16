/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:31:45 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 16:55:24 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	chek_position(char **extended_map, int i, int j)
{
	int	flag;

	flag = 0;
	if (extended_map[i][j + 1] == '/')
		flag = 1;
	else if (j - 1 >= 0 && extended_map[i][j - 1] == '/')
		flag = 1;
	else if (i - 1 >= 0 && extended_map[i - 1][j] == '/')
		flag = 1;
	else if (extended_map[i + 1] && extended_map[i + 1][j] == '/')
		flag = 1;
	return (flag);
}

char	**create_map_expanded(t_game *g, int rows, int cols)
{
	int		i;
	int		j;
	char	**extended_map;

	i = 0;
	extended_map = allocate_expanded_map(rows, cols);
	while (g->board[i])
	{
		extended_map[i] = malloc((cols + 1 + 1) * sizeof(char));
		if (!extended_map[i])
			exit(1);
		j = -1;
		while (++j < cols + 1)
		{
			if (j < ft_strlen(g->board[i]) && g->board[i][j]
				&& g->board[i][j] != ' ')
				extended_map[i][j] = g->board[i][j];
			else
				extended_map[i][j] = '/';
		}
		extended_map[i][j] = '\0';
		i++;
	}
	extended_map[i] = NULL;
	return (extended_map);
}

void	free_extended_map(char **m)
{
	int	i;

	i = 0;
	if (m)
	{
		if (m[i])
		{
			while (m[i])
			{
				free(m[i]);
				i++;
			}
		}
		free(m);
	}
}

int	check_fist_linecolumn(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == '0')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] == '0')
			return (1);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] == '0')
			return (1);
		j++;
	}
	return (0);
}

int	padding_map_two(t_game *game, int rows, int cols)
{
	int		i;
	int		j;
	char	**extended_map;
	int		flag;

	i = 0;
	flag = 0;
	extended_map = create_map_expanded(game, rows, cols);
	while (flag == 0 && extended_map[i] != NULL)
	{
		j = 0;
		while (flag == 0 && extended_map[i][j] != '\0')
		{
			if (extended_map[i][j] == '0')
				flag = chek_position(extended_map, i, j);
			j++;
		}
		i++;
	}
	if (check_fist_linecolumn(extended_map))
		return (free_extended_map(extended_map), 1);
	free_extended_map(extended_map);
	return (flag);
}
