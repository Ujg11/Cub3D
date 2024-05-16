/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:28:47 by agrimald          #+#    #+#             */
/*   Updated: 2024/04/25 19:04:20 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
/*int	main(int ac, char **av)
{
	char *mio;
	char *suyo;

	if(ac == 2)
	{
		mio = ft_strdup(av[1]);
		suyo = strdup(av[1]);
		printf("ADDR:%p:%s:\nADDR:%p:%s:\n",&mio, mio, &suyo, suyo);
	}
	return (0);
}*/
