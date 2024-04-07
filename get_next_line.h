/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:53:20 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/04/07 23:04:53 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read(char *conservator, int fd);
char	*copy_line(char **conservator);
char	*ft_substr(char *s, int len);
int		check_new(char *conservator);
char	*ft_strdup(char *s1, int j);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif