/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:40:54 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/03/22 21:58:29 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*conservator[OPEN_MAX];
	char		*one_line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (fd >= 0)
			free(conservator[fd]);
		conservator[fd] = NULL;
		return (NULL);
	}
	conservator[fd] = ft_read(conservator[fd], fd);
	if (check_new(conservator[fd]) == -1)
	{
		if (conservator[fd] == NULL || *conservator[fd] == '\0')
			return (free(conservator[fd]), conservator[fd] = NULL, NULL);
		str = conservator[fd];
		conservator[fd] = NULL;
		return (str);
	}
	one_line = copy_line(&(conservator[fd]));
	if (one_line == NULL)
		return (conservator[fd] = NULL, NULL);
	return (one_line);
}
