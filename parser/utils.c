/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:41:23 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/06 20:32:18 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_comma(char *floor, char *sky)
{
	int	i;
	int	n_commas;

	n_commas = 0;
	i = -1;
	while (floor[++i])
	{
		if (floor[i] == ',')
			++n_commas;
	}
	i = -1;
	while (sky[++i])
	{
		if (sky[i] == ',')
			++n_commas;
	}
	if (n_commas != 4)
		return (1);
	return (0);
}

void	error_parser(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
