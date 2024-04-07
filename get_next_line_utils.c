/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:53 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/04/07 23:04:20 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char *s, int len)
{
	int		i;
	char	*d;

	if (!s)
		return (NULL);
	i = 0;
	if (*s == '\0')
		return (NULL);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	while (len--)
	{
		d[i] = s[i];
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
		return (NULL);
	s2 = malloc((ft_strlen(s1 + j) + 1) * sizeof(char));
	if (!s2)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	while (s1[j])
	{
		s2[i] = s1[j];
		i++;
		j++;
	}
	s2[i] = '\0';
	free(s1);
	s1 = NULL;
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*d;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	d = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
	{
		free(s1);
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
	s1 = 0;
	return (d);
}
