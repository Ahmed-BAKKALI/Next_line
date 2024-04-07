/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:50 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/04/07 23:03:04 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new(char *conservator)
{
	int	i;

	i = 0;
	if (conservator == NULL)
		return (-1);
	while (conservator && conservator[i] != '\0')
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

	if(*conservator == NULL)
		return (NULL);
	one_line = ft_substr(*conservator, check_new(*conservator) + 1);
	if (one_line == NULL)
		return (NULL);
	*conservator = ft_strdup(*conservator, check_new(*conservator) + 1);
	return (one_line);
}

char	*ft_read(char *conservator, int fd)
{
	char	*freader;
	int		rd;
	int		i;

	rd = -2;
	i = -1;
	freader = NULL;
	while (i == -1)
	{
		freader = malloc(BUFFER_SIZE + 1);
		if (!freader)
			return (free(conservator), conservator = NULL, NULL);
		rd = read(fd, freader, BUFFER_SIZE);
		if (rd == -1)
			return (free(freader), NULL);
		freader[rd] = '\0';
		i = check_new(freader);
		if (rd == 0)
			return(free(freader), freader = NULL, conservator);
		conservator = ft_strjoin(conservator, freader);
		if (conservator == NULL)
			return (free(freader), freader = NULL, NULL);
		free(freader);
	}
	return (freader = NULL, conservator);
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
		return (free(conservator), conservator = NULL, NULL);
	return (one_line);
}
