/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:45:24 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 16:56:59 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	search_comma(char *str, int comma, int *i)
{
	int	aux;

	aux = 0;
	while (aux < comma && str[*i])
	{
		if (str[*i] == ',')
			aux++;
		*i += 1;
	}
}

int	ft_atoi(char *str, int comma)
{
	int	sign;
	int	num;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	search_comma(str, comma, &i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
/*int main()
{
	char o[] = "hola123a231bc";
	printf("%d\n", ft_atoi(o));
	char p[] = "hola123a231bc";
	printf("%d\n", atoi(p));
}*/
