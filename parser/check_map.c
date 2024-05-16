/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:52:53 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/06 20:29:21 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_rowss(char *file)
{
	int		count;
	int		fd;
	char	ch;

	count = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_parser("Open failed");
	while (read(fd, &ch, 1) > 0)
	{
		if (ch == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	check_map(char *file, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	i = -1;
	game->rows = count_rowss(file);
	if (game->rows <= 8)
		error_parser("Mapa muy grande mano");
	game->map = (char **)malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
		error_parser("Oe el mapa no existe");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_parser("fd < a 0");
	while (++i < game->rows)
	{
		line = get_next_line(fd);
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			error_parser("Fallo con el strdup");
		free(line);
	}
	game->map[i] = NULL;
	close(fd);
	return (0);
}
