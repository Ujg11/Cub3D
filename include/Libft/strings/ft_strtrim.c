/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:53:55 by agrimald          #+#    #+#             */
/*   Updated: 2024/05/16 16:57:22 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	search_char(char c, const char *s)
{
	while (*s != '\0')
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

static char	*copy_chars(char *dst, int len, char *src)
{
	char	*dst_ptr;
	int		i;

	i = 0;
	dst_ptr = dst;
	while (i < len)
	{
		dst_ptr[i] = src[i];
		i++;
	}
	dst_ptr[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*trimmed;
	int		len_new;
	int		len_s1;
	int		i;
	char	*ptr;

	len_new = 0;
	len_s1 = ft_strlen(s1);
	i = 0;
	while (search_char(s1[i], set) && s1[i] != '\0')
		i++;
	ptr = (char *)&s1[i];
	if (s1[i] != '\0')
	{
		while (search_char(s1[len_s1 - 1], set))
			len_s1--;
		len_new = len_s1 - i;
		trimmed = malloc((len_new + 1) * sizeof(char));
		if (trimmed == NULL)
			return (0);
		free(s1);
		trimmed = copy_chars(trimmed, len_new, ptr);
		return (trimmed);
	}
	return (free(s1), ft_strdup(""));
}
