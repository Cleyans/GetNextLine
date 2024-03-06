/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:45:16 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/20 11:18:55 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	total_len = (ft_strlen(s1) + ft_strlen(s2));
	result = (char *)malloc(total_len + 1);
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_memcpy(result, s1, ft_strlen(s1));
	if (s2 != NULL)
		ft_memcpy(result + ft_strlen(s1), s2, ft_strlen(s2));
	result[total_len] = '\0';
	free(s1);
	return (result);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strchr(char *s, int c)
{
	int	index;

	index = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}
