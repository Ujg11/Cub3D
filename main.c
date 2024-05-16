/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:32:27 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 16:07:52 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_parser("Error: Que fue mano?? 🤨");
	check_xtension(argv[1]);
	start_parser(argv[1], &game);
	change_map(&game);
	raytracing(game);
	return (0);
}
