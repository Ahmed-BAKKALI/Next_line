/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:43:08 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/03/23 00:10:35 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*d;

	if (!s)
		return (0);
	i = 0;
	if (*s == '\0')
		return (NULL);
	// if (len > ft_strlen(s + start))
	// 	len = ft_strlen(s + start);
	d = malloc(len + 1);
	if (d == NULL)
		return (NULL);
	while (len--)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(char *s1, int j)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	s2 = malloc((ft_strlen(s1 + j) + 1) * sizeof(char));
	if (!s2)
	{
		free(s1);
		s1 = 0;
		return (0);
	}
	while (s1[j])
	{
		s2[i] = s1[j];
		i++;
		j++;
	}
	s2[i] = '\0';
	free(s1);
	s1 = 0;
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*d;

	i = 0;
	j = 0;
	d = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	free(s1);
	return (d);
}
