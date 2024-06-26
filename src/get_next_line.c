/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:07:06 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/13 17:07:06 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*ligne;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reserve = ft_read(fd, reserve);
	if (!reserve)
		return (NULL);
	ligne = ft_extraire_ligne(reserve);
	reserve = ft_ligne_suivante(reserve);
	return (ligne);
}

char	*ft_read(int fd, char *reserve)
{
	int		verif_return;
	char	*str;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	verif_return = 1;
	while (ft_strchr(reserve, '\n') == NULL && verif_return != 0)
	{
		verif_return = read(fd, str, BUFFER_SIZE);
		if (verif_return == -1)
		{
			free(reserve);
			free(str);
			return (NULL);
		}
		str[verif_return] = '\0';
		reserve = ft_strjoin(reserve, str);
	}
	free(str);
	return (reserve);
}

char	*ft_extraire_ligne(char *reserve)
{
	char	*ligne;
	int		index;

	index = 0;
	if (!reserve[index])
		return (NULL);
	while (reserve[index] && reserve[index] != '\n')
		index++;
	ligne = (char *)malloc(sizeof(char) * index + 2);
	if (!ligne)
		return (NULL);
	index = 0;
	while (reserve[index] && reserve[index] != '\n')
	{
		ligne[index] = reserve[index];
		index++;
	}
	if (reserve[index] == '\n')
	{
		ligne[index] = '\n';
		index++;
	}
	ligne[index] = '\0';
	return (ligne);
}

char	*ft_ligne_suivante(char *reserve)
{
	char	*suivant;
	int		index;
	int		index_suivant;

	index = 0;
	index_suivant = 0;
	while (reserve[index] && reserve[index] != '\n')
		index++;
	if (!reserve[index])
	{
		free(reserve);
		return (NULL);
	}
	suivant = (char *)malloc(sizeof(char) * ft_strlen(reserve) - index + 1);
	if (!suivant)
		return (NULL);
	index++;
	while (reserve[index])
		suivant[index_suivant++] = reserve[index++];
	suivant[index_suivant] = '\0';
	free(reserve);
	return (suivant);
}
