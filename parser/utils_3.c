/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:20:09 by ojimenez          #+#    #+#             */
/*   Updated: 2024/05/16 16:55:30 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**allocate_expanded_map(int rows, int cols)
{
	char	**ex_map;

	cols = 0;
	ex_map = malloc((rows + 1) * sizeof(char *));
	if (!ex_map)
	{
		perror("Fail in malloc\n");
		exit(1);
	}
	return (ex_map);
}

int	only_one_player(char **map, char *or)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == or[0] || map[i][j] == or[1] || map[i][j] == or[2]
					|| map[i][j] == or[3])
				flag++;
			j++;
		}
		i++;
	}
	if (flag >= 2)
		return (1);
	return (0);
}

int	check_string(char *s)
{
	int	i;

	i = 1;
	if (s[0] == ',')
		return (1);
	while (s[i])
	{
		if (s[i - 1] == ',' && s[i] == ',')
			return (1);
		i++;
	}
	if (s[i - 1] == ',' && s[i] == '\0')
		return (1);
	return (0);
}
