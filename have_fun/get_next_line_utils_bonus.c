/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:26:23 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/27 15:51:58 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	len;
	int	i;
	char	*tab;
	char	*newstr;

	newstr = NULL;	
	len = (ft_strlen(s1) + ft_strlen(s2));
	tab = (char *)malloc(sizeof(char) * len + 1);
	newstr = tab;
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	tab[len] = '\0';
	free(s1);
	return (newstr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str && str[i] != '\0')
		i++;
	return (i);
}
