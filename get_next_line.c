/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:50 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/03/23 00:21:55 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new(char *conservator)
{
	int	i;

	i = 0;
	if (conservator == NULL)
		return (-1);
	while (conservator[i] != '\0')
	{
		if (conservator[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*copy_line(char **conservator)
{
	char	*one_line;

	one_line = ft_substr(*conservator, 0, check_new(*conservator) + 1);
	if (one_line == NULL)
	{
		free(*conservator);
		return (NULL);
	}
	*conservator = ft_strdup(*conservator, check_new(*conservator) + 1);
	return (one_line);
}

char	*ft_read(char *conservator, int fd)
{
	char	*freader;
	int		rd;
	int		i;

	rd = -2;
	i = 0;
	freader = malloc(BUFFER_SIZE + 1);
	if (!freader)
		return (free(conservator), conservator = NULL, NULL);
	while (check_new(conservator) == -1)
	{
		rd = read(fd, freader, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		if (rd == 0)
			break ;
		freader[rd] = '\0';
		conservator = ft_strjoin(conservator, freader);
		if (conservator == NULL)
			return (freader = NULL, NULL);
	}
	free(freader);
	freader = NULL;
	return (conservator);
}

char	*get_next_line(int fd)
{
	static char	*conservator;
	char		*one_line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(conservator);
		conservator = NULL;
		return (NULL);
	}
	conservator = ft_read(conservator, fd);
	if (check_new(conservator) == -1)
	{
		if (conservator == NULL || *conservator == '\0')
			return (free(conservator), conservator = NULL, NULL);
		str = conservator;
		conservator = NULL;
		return (str);
	}
	one_line = copy_line(&conservator);
	if (one_line == NULL)
		return (conservator = NULL, NULL);
	return (one_line);
}
