/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:45:24 by agrimald          #+#    #+#             */
/*   Updated: 2024/04/25 18:54:29 by agrimald         ###   ########.fr       */
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
	//while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	//	i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		//if (!(str[i] >= '0' && str[i] <= '9'))
		//	return (0);
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
