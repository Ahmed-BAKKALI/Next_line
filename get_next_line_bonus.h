/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbakkal <ahbakkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:39:54 by ahbakkal          #+#    #+#             */
/*   Updated: 2024/03/22 21:57:42 by ahbakkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read(char *conservator, int fd);
char	*copy_line(char **conservator);
char	*ft_substr(char *s, int start, int len);
int		check_new(char *conservator);
char	*ft_strdup(char *s1, int j);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
